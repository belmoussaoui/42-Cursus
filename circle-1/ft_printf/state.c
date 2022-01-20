/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:51:06 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/20 02:14:04 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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