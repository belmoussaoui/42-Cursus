/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:43:08 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/21 17:19:37 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(char c, t_state *state)
{
	int		len;
	int		i;
	int		res;

	len = 0;
	i = 0;
	res = 0;
	res += padding_blank(state, 1);
	len = 1;
	if (state->precision >= 0 && state->precision < len)
		len = state->precision;
	ft_putchar_fd(c, 1);
	while (state->is_left_justify && state->width - len > 0)
	{
		res++;
		state->width--;
		ft_putchar_fd(' ', 1);
	}
	return (1 + res);
}
