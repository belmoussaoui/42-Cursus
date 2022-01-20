/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:25:12 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/20 07:00:51 by bel-mous         ###   ########.fr       */
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
	int	len;
	char pad;

	len = 0;
	pad = ' ';
	if (state->is_padded_zero || state->precision > 0)
		pad = '0';
	if (state->width > 0)
		len = state->width - ft_nbrlen(nbr);
	if (state->precision > 0)
		len = state->precision - ft_nbrlen(nbr);
	if (nbr >= 0 && state->is_sign)
	{
		ft_putchar_fd('+', 1);
		state->length++;
	}
	if (nbr >= 0 && !state->is_sign && state->is_blank)
	{
		ft_putchar_fd(' ', 1);
		state->length++;
	}
	
	if (nbr < 0 && pad == '0')
	{
		ft_putchar_fd('-', 1);
		if (state->precision >= 0)
			len++;
		state->length++;
		nbr *= -1;
	}
	if (!state->is_left_justify)
	{
		while (len > 0)
		{
			ft_putchar_fd(pad, 1);
			state->length++;
			len--;
		}
	}
	ft_putlli_fd(nbr, 1);
	while (len > 0)
	{
		ft_putchar_fd(pad, 1);
		state->length++;
		len--;
	}
	return (ft_nbrlen(nbr));
}

int printhex(unsigned long long int nbr, t_state *state, int (*f) (int))
{
	int	len;
	char pad;

	len = 0;
	pad = ' ';
	if (state->is_padded_zero || state->precision > 0)
		pad = '0';
	if (state->width > 0)
		len = state->width - ft_hexlen(nbr);
	if (state->precision > 0)
		len = state->precision - ft_hexlen(nbr);
	if ((state->is_prefix == 1 && nbr > 0) || state->is_prefix == 2)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(f('x'), 1);
		state->length += 2;
		len -= 2; 
	}
	if (!state->is_left_justify)
	{
		while (len > 0)
		{
			ft_putchar_fd(pad, 1);
			state->length++;
			len--;
		}
	}
	ft_puthex_fd(nbr, f, 1);
	while (len > 0)
	{
		ft_putchar_fd(pad, 1);
		state->length++;
		len--;
	}
	return (ft_hexlen(nbr));
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
