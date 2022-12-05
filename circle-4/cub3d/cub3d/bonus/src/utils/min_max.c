/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:53:54 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/04 22:05:08 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int64_t	min(int64_t a, int64_t b)
{
	return ((a <= b) * a + (b < a) * b);
}

int64_t	max(int64_t a, int64_t b)
{
	return ((a >= b) * a + (b > a) * b);
}