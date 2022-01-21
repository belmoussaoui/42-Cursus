/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:35:22 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/21 17:22:03 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printhex(unsigned long long int nbr, t_state *state, int (*f) (int))
{
	int	nbrlen;
	int	res;

	nbrlen = ft_hexlen(nbr);
	res = 0;
	if (state->precision == 0 && nbr == 0)
		nbrlen = 0;
	if ((state->is_prefix == 1 && nbr > 0) || state->is_prefix == 2)
		nbrlen += 2;
	res += padding_blank(state, nbrlen);
	if ((state->is_prefix == 1 && nbr > 0) || state->is_prefix == 2)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(f('x'), 1);
	}
	res += padding_zero(state, nbrlen);
	if (state->precision != 0 || nbr != 0)
		ft_puthex_fd(nbr, f, 1);
	while (state->width - nbrlen > 0 && state->is_left_justify)
	{
		res++;
		state->width--;
		ft_putchar_fd(' ', 1);
	}
	return (res + nbrlen);
}
