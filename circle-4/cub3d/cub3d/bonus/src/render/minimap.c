/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:17:38 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/13 22:00:14 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	init_rect(t_rect *rect, int size)
{
	rect->x = 0;
	rect->y = 0;
	rect->width = size;
	rect->height = size;
	rect->color = 0;
}

static int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			if (i < UI_H - 20 && i >= 20 && j >= -48 && j < UI_H + 30
				&& j + SCREEN_W / 2 + 380 < SCREEN_W)
				my_mlx_pixel_put(img, j + SCREEN_W / 2 + 380,
					i + SCREEN_H - UI_H, rect.color);
			j++;
		}
		i++;
	}
	return (0);
}

static void	drawline(t_img *img, t_vector p0, t_vector p1)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = p1.x - p0.x;
	delta_y = p1.y - p0.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = p0.x + SCREEN_W / 2 + 380;
	pixel_y = p0.y + SCREEN_H - UI_H;
	while (pixels)
	{
		if (pixel_x < SCREEN_W)
			my_mlx_pixel_put(img, pixel_x, pixel_y, 0xff0000);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

static void	render_miniplayer(t_img *img, t_game *g)
{
	t_rect		rect;
	t_vector	position0;
	t_vector	position1;
	t_vector	position2;
	t_player	p;

	p = g->player;
	init_rect(&rect, 6);
	rect.x = UI_H / 2;
	rect.y = UI_H / 2;
	rect.color = 0xFF0000;
	position0 = vector(rect.x + 3, rect.y + 3);
	position1 = vector((rect.x + 3 + (p.dir.x * 1 - p.plane.x) * 20),
			(rect.x + 3 - (p.dir.y - p.plane.y) * 20));
	position2 = vector((rect.y + 3 + (p.dir.x * 1 + p.plane.x) * 20),
			(rect.y + 3 - (p.dir.y + p.plane.y) * 20));
	drawline(img, position0, position1);
	drawline(img, position0, position2);
	drawline(img, position1, position2);
	render_rect(img, rect);
}

void	render_minimap(t_img *img, t_game *g)
{
	int		i;
	t_rect	rect;
	t_map	map;

	init_rect(&rect, UI_H);
	rect.color = MMAP_COLOR1;
	render_rect(img, rect);
	map = g->map;
	i = 0;
	init_rect(&rect, TILEMAP_SIZE);
	while (i < map.height * map.width)
	{
		rect.x = (i % map.width) * TILEMAP_SIZE
			- (TILEMAP_SIZE * (g->player.pos.x - 6.25)) + 3;
		rect.y = ((map.height * map.width - 1 - i) / map.width) * TILEMAP_SIZE
			- (TILEMAP_SIZE * (g->map.height - g->player.pos.y - 6.25)) + 3;
		rect.color = 0x000000;
		if (map.data[i] == 1)
			rect.color = MMAP_COLOR1;
		else if (map.data[i] == 0)
			rect.color = MMAP_COLOR2;
		render_rect(img, rect);
		i++;
	}
	render_miniplayer(img, g);
}
