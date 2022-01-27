/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:26:24 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/22 19:22:17 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	specifier_int(va_list ap, t_state *state)
{
	int	value;

	value = va_arg(ap, int);
	if (value < 0 && state->precision >= 0)
		state->precision++;
	if (state->precision >= 0)
		state->is_padded_zero = 0;
	state->length += printnbr(value, state);
}

void	specifier_str(va_list ap, t_state *state)
{
	char	*value;

	value = va_arg(ap, char *);
	if (!value)
		state->length += printstr("(null)", state);
	else
		state->length += printstr(value, state);
}

void	specifier_unsigned(va_list ap, t_state *state)
{
	unsigned int	value;

	value = va_arg(ap, unsigned int);
	if (state->precision >= 0)
		state->is_padded_zero = 0;
	state->length += printnbr(value, state);
}

void	specifier_hex(va_list ap, t_state *state, int (*f)(int))
{
	unsigned int	value;

	value = va_arg(ap, unsigned int);
	if (value == 0)
		state->is_prefix = 0;
	if (state->precision >= 0 || state->is_left_justify)
		state->is_padded_zero = 0;
	state->length += printhex(value, state, f);
}

void	specifier_ptr(va_list ap, t_state *state)
{
	unsigned long	value;

	state->is_prefix = 1;
	if (state->precision >= 0 || state->is_left_justify)
		state->is_padded_zero = 0;
	value = va_arg(ap, unsigned long);
	state->length += printhex(value, state, ft_tolower);
}
