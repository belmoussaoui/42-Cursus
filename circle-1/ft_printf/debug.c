/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:33:46 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/19 23:38:16 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"
#include <stdio.h>

void	debug(t_state *state)
{
	printf("sharp = %d\n", state->is_prefix);
	printf("plus = %d\n", state->is_sign);
	printf("space = %d\n", state->is_blank);
	printf("minus = %d\n", state->is_left_justify);
	printf("zero = %d\n", state->is_padded_zero);
	printf("precision = %d\n", state->precision);
	printf("width = %d\n", state->width);
	printf("length = %d\n", state->length);
}