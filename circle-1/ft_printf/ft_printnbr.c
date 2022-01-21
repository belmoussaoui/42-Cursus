/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:30:49 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/21 18:08:15 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	calcul_nbrlen(long long int nbr, t_state *state)
{
	int	len;

	len = ft_nbrlen(nbr);
	if (state->precision == 0 && nbr == 0)
		len = 0;
	return (len);
}

int	padding_zero(t_state *state, int nbrlen)
{
	int	len;

	len = 0;
	while (state->precision - nbrlen > 0
		|| (state->is_padded_zero && state->width - nbrlen > 0))
	{
		len++;
		state->precision--;
		state->width--;
		ft_putchar_fd('0', 1);
	}
	return (len);
}

int	padding_blank(t_state *state, int nbrlen)
{
	int	res;

	res = 0;
	while (!state->is_left_justify && state->width - nbrlen > 0
		&& !state->is_padded_zero)
	{
		if (state->precision >= state->width)
			break ;
		res++;
		state->width--;
		ft_putchar_fd(' ', 1);
	}
	return (res);
}

long long int	set_sign(long long int nbr, t_state *state)
{
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
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr *= -1;
	}
	return (nbr);
}

int	printnbr(long long int nbr, t_state *state)
{
	int	nbrlen;
	int	res;

	nbrlen = calcul_nbrlen(nbr, state);
	res = 0;
	res += padding_blank(state, nbrlen);
	nbr = set_sign(nbr, state);
	res += padding_zero(state, nbrlen);
	if (state->precision != 0 || nbr != 0)
		ft_putlli_fd(nbr, 1);
	while (state->is_left_justify && state->width - nbrlen > 0)
	{
		res++;
		state->width--;
		ft_putchar_fd(' ', 1);
	}
	return (res + nbrlen);
}
