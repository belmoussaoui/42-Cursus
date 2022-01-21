/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:41:28 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/21 22:20:09 by bel-mous         ###   ########.fr       */
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
	int		len;
	int		i;
	int		res;

	len = ft_strlen(str);
	res = 0;
	if (state->precision >= 0 && state->precision < len)
		len = state->precision;
	if (!state->is_left_justify)
		res += padding_blank(state, len);
	i = 0;
	while (str[i] && (i < state->precision || state->precision == -1))
		ft_putchar_fd(str[i++], 1);
	state->precision = 0;
	if (state->is_left_justify)
		res += padding_blank(state, len);
	return (i + res);
}
