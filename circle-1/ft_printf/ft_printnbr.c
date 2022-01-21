/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:30:49 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/21 21:44:01 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_symbol(long long int nbr, t_state *state)
{
	if (nbr >= 0 && state->is_sign)
		ft_putchar_fd('+', 1);
	if (nbr >= 0 && !state->is_sign && state->is_blank)
		ft_putchar_fd(' ', 1);
	if (nbr < 0)
		ft_putchar_fd('-', 1);
	if (nbr >= 0 && (state->is_sign || state->is_blank))
		state->length++;
}

int	printnbr(long long int nbr, t_state *state)
{
	int	nbrlen;
	int	res;

	res = 0;
	nbrlen = ft_nbrlen(nbr);
	if (state->precision == 0 && nbr == 0)
		nbrlen = 0;
	if (!state->is_left_justify && !state->is_padded_zero)
		res += padding_blank(state, nbrlen);
	set_symbol(nbr, state);
	if (nbr < 0)
		nbr *= -1;
	res += padding_zero(state, nbrlen);
	if (state->precision != 0 || nbr != 0)
		ft_putlli_fd(nbr, 1);
	if (state->is_left_justify)
		res += padding_blank(state, nbrlen);
	return (res + nbrlen);
}

void	set_prefix(t_state *state, int (*f) (int))
{
	if (state->is_prefix)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(f('x'), 1);
	}
}

int	printhex(unsigned long long int nbr, t_state *state, int (*f) (int))
{
	int	nbrlen;
	int	res;

	nbrlen = ft_hexlen(nbr);
	res = 0;
	if (state->precision == 0 && nbr == 0)
		nbrlen = 0;
	if (state->is_prefix)
		nbrlen += 2;
	if (!state->is_left_justify && !state->is_padded_zero)
		res += padding_blank(state, nbrlen);
	set_prefix(state, f);
	res += padding_zero(state, nbrlen);
	if (state->precision != 0 || nbr != 0)
		ft_puthex_fd(nbr, f, 1);
	if (state->is_left_justify)
		res += padding_blank(state, nbrlen);
	return (res + nbrlen);
}
