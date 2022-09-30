/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:00:21 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/17 13:15:31 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_angle(t_vector v1, t_vector v2)
{
	double	angle;

	angle = (atan2(v1.x, v1.y) - atan2(v2.x, v2.y));
	return (angle + 2 * M_PI * (angle < 0));
}

double	get_fov_ratio(t_game *g)
{
	return (g->player.fov / (2 * M_PI));
}

void	skycasting(int x0, int x1, t_img *img, t_game *g)
{
	double	angle;
	int		tx;
	int		ty;
	int		ty_range;
	int		y;

	angle = get_angle(vector(0, 1), vector_add(
				g->player.dir,
				vector_scalar_multiplication(
					g->player.plane,
					(double)2 * x0 / (double)g->img_w - 1)));
	tx = g->map.ceil_repeat * angle / (2 * M_PI) * g->sky.width;
	ty_range = g->map.ceil_repeat * get_fov_ratio(g)
		* g->sky.width / g->img_w * (g->img_h / 2);
	y = 0;
	while (y < g->img_h / 2)
	{
		ty = y * (double)ty_range / (double)(g->img_h / 2);
		ty += (g->sky.height - ty_range) / 2;
		my_mlx_pixel_put(img, x0, y, mlx_get_pixel(&g->sky, tx, ty));
		y++;
	}
	if (x0 < x1)
		return (skycasting(x0 + 1, x1, img, g));
}
