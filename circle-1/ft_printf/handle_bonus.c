/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:24:32 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/21 16:26:19 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char c)
{
	return (c == '#' || c == '+' || c == ' ' || c == '-' || c == '0');
}

void	set_flag(char c, t_state *state)
{
	if (c == '#')
		state->is_prefix = 1;
	if (c == '+')
		state->is_sign = 1;
	if (c == ' ')
		state->is_blank = 1;
	if (c == '-')
		state->is_left_justify = 1;
	if (c == '0')
		state->is_padded_zero = 1;
}

void	handle_flags(const char *format, t_state *state)
{
	char	c;

	c = format[state->pos];
	while (is_flag(c))
	{
		set_flag(c, state);
		state->pos++;
		c = format[state->pos];
	}
}

void	handle_width(const char *format, t_state *state)
{
	char	c;

	c = format[state->pos];
	while (ft_isdigit(c))
	{
		state->width = state->width * 10 + c - '0';
		state->pos++;
		c = format[state->pos];
	}
}

void	handle_precision(const char *format, t_state *state)
{
	char	c;

	c = format[state->pos];
	if (c == '.')
	{
		state->pos++;
		c = format[state->pos];
		state->precision = 0;
		while (ft_isdigit(c))
		{
			state->precision = state->precision * 10 + c - '0';
			state->pos++;
			c = format[state->pos];
		}
	}
	if (state->precision >= 0)
		state->is_padded_zero = 0;
}
