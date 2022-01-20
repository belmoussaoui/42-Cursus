/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:26:24 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/20 07:00:30 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void specifier_percentage(t_state *state)
{
	state->length += printchar('%', state);
}

void	specifier_int(va_list ap, t_state *state)
{
	int	value;
	
	value = va_arg(ap, int);
	state->length += printnbr(value, state);
}

void	specifier_char(va_list ap, t_state *state)
{
	char	value;
	
	value = (char) va_arg(ap, int);
	state->length += printchar(value, state);
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
	state->length += printnbr(value, state);
}

void	specifier_hex(va_list ap, t_state *state, int (*f)(int))
{
	unsigned int	value;
	
	value = va_arg(ap, unsigned int);
	state->length += printhex(value, state, f);
}

void	specifier_ptr(va_list ap, t_state *state)
{
	unsigned long	value;
	
	state->is_prefix = 2;
	value = va_arg(ap, unsigned long);
	state->length += printhex(value, state, ft_tolower);
}