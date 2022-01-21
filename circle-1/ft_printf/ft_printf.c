/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:25:12 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/21 05:50:38 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(char c, t_state *state)
{
	int	len;
	char pad;

	len = 0;
	pad = ' ';
	if (state->is_padded_zero || state->precision > 0)
		pad = '0';
	if (state->width > 0)
		len = state->width - 1;
	if (state->precision > 0)
		len = state->precision - 1;
	if (!state->is_left_justify)
	{
		while (len > 0)
		{
			ft_putchar_fd(pad, 1);
			state->length++;
			len--;
		}
	}		
	ft_putchar_fd(c, 1);
	while (len > 0)
	{
		ft_putchar_fd(pad, 1);
		state->length++;
		len--;
	}
	return (1);
}

int printstr(char *str, t_state *state)
{
	int	len;
	char	pad;
	int		i;

	len = 0;
	i = 0;
	pad = ' ';
	if (state->is_padded_zero)
		pad = '0';
	if (state->width > 0)
		len = state->width - ft_strlen(str);
	if (!state->is_left_justify)
	{
		while (len > 0)
		{
			ft_putchar_fd(pad, 1);
			state->length++;
			len--;
		}
	}
	while (str[i] && (i < state->precision || state->precision == -1))
		ft_putchar_fd(str[i++], 1);
	while (len > 0)
	{
		ft_putchar_fd(pad, 1);
		state->length++;
		len--;
	}
	return (i);
}

int printnbr(long long int nbr, t_state *state)
{
	int max;
	int min;
	int nbrlen;
	int res;

	nbrlen = ft_nbrlen(nbr);
	res = 0;
	max = state->width;
	min = state->precision;
	
	// check si on affiche quelque chose pour le 0
	if (state->precision == 0 && nbr == 0)
		nbrlen = 0;
	// la precision ne prends pas en compte le -
	if (nbr < 0)
		min++;
	// width of ' '
	while (!state->is_left_justify && max - nbrlen > 0)
	{
		// on affiche des 0 si la précision le permet!
		if ((state->is_padded_zero && state->precision == -1) || min >= max)
			break;
		res++;
		max--;
		ft_putchar_fd(' ', 1);
	}
	// precision
	// negative donc print en premier -
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr *= -1;
	}
	// padding 0
	while (min - nbrlen > 0 || (state->is_padded_zero && max - nbrlen > 0))
	{
		res++;
		min--;
		max--;
		ft_putchar_fd('0', 1);
	}
	// le cas ou precision = 0 pas afficher 0
	if (state->precision == 0 && nbr == 0)
		;
	else
		ft_putlli_fd(nbr, 1);
	// width avec left_justify
	while (state->is_left_justify && max - nbrlen > 0)
	{
		res++;
		max--;
		ft_putchar_fd(' ', 1);
	}
	return (res + nbrlen);
}

int printhex(unsigned long long int nbr, t_state *state, int (*f) (int))
{
	int max;
	int min;
	int nbrlen;
	int res;

	nbrlen = ft_hexlen(nbr);
	res = 0;
	max = state->width;
	min = state->precision;

	// check si on affiche quelque chose pour le 0
	if (state->precision == 0 && nbr == 0)
		nbrlen = 0;
	// si 0x le nombre est plus grand de 2
	if ((state->is_prefix == 1 && nbrlen > 0) || state->is_prefix == 2)
		nbrlen += 2;
	// width
	while (!state->is_left_justify && max - nbrlen > 0)
	{
		// on affiche des 0 si la précision le permet!
		if ((state->is_padded_zero && state->precision == -1) || min >= max)
			break;
		res++;
		max--;
		ft_putchar_fd(' ', 1);
	}
	if ((state->is_prefix == 1 && nbrlen > 0) || state->is_prefix == 2)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(f('x'), 1);
	}
	while (min - nbrlen > 0 || (state->is_padded_zero && max - nbrlen > 0))
	{
		res++;
		min--;
		max--;
		ft_putchar_fd('0', 1);
	}
	// le cas ou precision = 0 pas afficher 0
	if (state->precision == 0 && nbr == 0)
		;
	else
		ft_puthex_fd(nbr, f, 1);
	// width avec left_justify
	while (max - nbrlen > 0 && state->is_left_justify)
	{
		res++;
		max--;
		ft_putchar_fd(' ', 1);
	}
	return (res + nbrlen);
}

int ft_printf(const char * format, ...)
{
	va_list	args;
	t_state	state;

	va_start(args, format);
	state = initialize_state();
	while (format[state.pos] != '\0')
	{
		if(format[state.pos] != '%')
			state.length += printchar(format[state.pos], &state);
		else
		{
			handle_format(format, args, &state);
			clear_state(&state);
		}
		state.pos++;
	}
	va_end(args);
	return (state.length);
}
