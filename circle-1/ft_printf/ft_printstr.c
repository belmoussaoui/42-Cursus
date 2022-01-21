/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:41:28 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/21 17:18:22 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printstr(char *str, t_state *state)
{
	int		len;
	int		i;
	int		res;

	len = 0;
	i = 0;
	res = 0;
	res += padding_blank(state, ft_strlen(str));
	len = ft_strlen(str);
	if (state->precision >= 0 && state->precision < len)
		len = state->precision;
	while (str[i] && (i < state->precision || state->precision == -1))
		ft_putchar_fd(str[i++], 1);
	while (state->is_left_justify && state->width - len > 0)
	{
		res++;
		state->width--;
		ft_putchar_fd(' ', 1);
	}
	return (i + res);
}
