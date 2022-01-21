/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:06:15 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/21 20:48:23 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padding_blank(t_state *state, int arglen)
{
	int	res;

	res = 0;
	while (state->width - arglen > 0
		&& state->precision < state->width)
	{
		res++;
		state->width--;
		ft_putchar_fd(' ', 1);
	}
	return (res);
}

int	padding_zero(t_state *state, int arglen)
{
	int	res;

	res = 0;
	while (state->precision - arglen > 0
		|| (state->is_padded_zero && state->width - arglen > 0))
	{
		res++;
		state->width--;
		state->precision--;
		ft_putchar_fd('0', 1);
	}
	return (res);
}
