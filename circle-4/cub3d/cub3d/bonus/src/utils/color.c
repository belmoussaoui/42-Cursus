/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:22:32 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/15 15:57:51 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_r(int c)
{
	return ((c >> 16) & 0xFF);
}

int	get_g(int c)
{
	return ((c >> 8) & 0xFF);
}

int	get_b(int c)
{
	return (c & 0xFF);
}

int	rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return (r << 16 | g << 8 | b);
}

int	shade(int cf, int cb, double af, double ab)
{
	int	r;
	int	g;
	int	b;

	r = get_r(cf) * af + get_r(cb) * ab * (1 - af);
	g = get_g(cf) * af + get_g(cb) * ab * (1 - af);
	b = get_b(cf) * af + get_b(cb) * ab * (1 - af);
	return (rgb(r, g, b));
}
