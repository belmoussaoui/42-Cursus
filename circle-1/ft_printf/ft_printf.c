/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:25:12 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/21 16:43:12 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_format(const char *format, va_list args, t_state *state)
{
	int	i;

	state->pos++;
	handle_flags(format, state);
	handle_width(format, state);
	handle_precision(format, state);
	i = state->pos;
	if (format[i] == 'i' || format[i] == 'd')
		specifier_int(args, state);
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
	else if (format[i] == 'c')
		state->length += printchar(va_arg(args, int), state);
	else
		state->length += printchar('%', state);
}

t_state	initialize_state(void)
{
	t_state	state;

	state.pos = 0;
	state.width = 0;
	state.length = 0;
	state.is_left_justify = 0;
	state.is_padded_zero = 0;
	state.is_sign = 0;
	state.is_blank = 0;
	state.is_prefix = 0;
	state.precision = -1;
	return (state);
}

void	clear_state(t_state *state)
{
	state->width = 0;
	state->is_left_justify = 0;
	state->is_padded_zero = 0;
	state->is_sign = 0;
	state->is_blank = 0;
	state->is_prefix = 0;
	state->precision = -1;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_state	state;

	va_start(args, format);
	state = initialize_state();
	while (format[state.pos] != '\0')
	{
		if (format[state.pos] != '%')
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
