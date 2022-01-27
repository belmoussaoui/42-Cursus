/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:41:28 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/22 00:24:12 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(char c, t_state *state)
{
	int		res;

	res = 0;
	if (!state->is_left_justify && !state->is_padded_zero)
		res += padding_blank(state, 1);
	res += padding_zero(state, 1);
	ft_putchar_fd(c, 1);
	if (state->is_left_justify)
		res += padding_blank(state, 1);
	return (1 + res);
}

int	printstr(char *str, t_state *state)
{
	int	len;
	int	i;
	int	res;
	int	min;

	min = state->precision;
	len = ft_strlen(str);
	res = 0;
	if (state->precision >= 0 && state->precision < len)
		len = state->precision;
	state->precision = 0;
	if (!state->is_left_justify && !state->is_padded_zero)
		res += padding_blank(state, len);
	if (state->is_padded_zero && !state->is_left_justify)
		res += padding_zero(state, len);
	state->precision = min;
	i = 0;
	while (str[i] && (i < state->precision || state->precision == -1))
		ft_putchar_fd(str[i++], 1);
	state->precision = 0;
	if (state->is_left_justify)
		res += padding_blank(state, len);
	return (i + res);
}
