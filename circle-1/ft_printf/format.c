/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:20:47 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/20 06:05:36 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_format(const char *format, va_list args, t_state *state)
{
	int i;

	state->pos++;
	handle_flags(format, state);
	handle_width(format, state);
	handle_precision(format, state);
	i = state->pos;
	if (format[i] == 'i' || format[i] == 'd')
		specifier_int(args, state);
	else if (format[i] == 'c')
		specifier_char(args, state);
	else if (format[i] == 's')
		specifier_str(args, state);
	else if (format[i] == 'u')
		specifier_unsigned(args, state);
	else if (format[i] == 'x')
		specifier_hex(args, state, ft_tolower);
	else if (format[i] == 'X')
		specifier_hex(args, state, ft_toupper);
	else if (format[i] == 'p')
		specifier_ptr(args, state);
	else
		specifier_percentage(state);
}