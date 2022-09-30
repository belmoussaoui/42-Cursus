/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:32:24 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/17 13:15:27 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_line(int y, t_scanline *scanline, t_img *img, t_game *g)
{
	int				x;
	int				tx;
	int				ty;
	unsigned int	h;
	unsigned int	w;

	x = 0;
	h = 1 << ((sizeof(unsigned int) << 3) - __builtin_clz(g->floor.height));
	w = 1 << ((sizeof(unsigned int) << 3) - __builtin_clz(g->floor.width));
	while (x < g->img_w)
	{
		tx = (int)(w * (scanline->floor.x - (int)scanline->floor.x)) & (w - 1);
		ty = (int)(h * (scanline->floor.y - (int)scanline->floor.y)) & (h - 1);
		tx *= (double)g->floor.height / w;
		ty *= (double)g->floor.height / h;
		scanline->floor.x += scanline->step.x;
		scanline->floor.y += scanline->step.y;
		my_mlx_pixel_put(img, x, y, mlx_get_pixel(&g->floor, tx, ty));
		x++;
	}
}

void	floorcasting(int y0, int y1, t_img *img, t_game *g)
{
	t_vector	ray_dir_0;
	t_vector	ray_dir_1;
	double		row_dist;
	t_scanline	scanline;

	ray_dir_0 = vector_sub(g->player.dir, g->player.plane);
	ray_dir_1 = vector_add(g->player.dir, g->player.plane);
	row_dist = (0.5 * g->img_h) / (y0 - g->img_h / 2);
	scanline.step.x = row_dist * (ray_dir_1.x - ray_dir_0.x) / g->img_w;
	scanline.step.y = row_dist * (ray_dir_1.y - ray_dir_0.y) / g->img_w;
	scanline.floor.x = g->player.pos.x + row_dist * ray_dir_0.x;
	scanline.floor.y = g->player.pos.y + row_dist * ray_dir_0.y;
	draw_line(y0, &scanline, img, g);
	if (y0 < y1)
		return (floorcasting(y0 + 1, y1, img, g));
}
