/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:51:58 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/21 02:02:27 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	draw_tile(t_render *render, t_sprite *sprite, int x, int y)
{
	mlx_put_image_to_window(render->mlx, render->window, sprite->image, x, y);
}

void	draw_map(t_render *render, t_backstage *backstage, t_map *map)
{
	(void)	backstage;
	// void backstage
	mlx_put_image_to_window(render->mlx, render->window, map->tilemap.image,
		map->x, map->y);
}

void	draw_tilemap(t_backstage *backstage, t_map *map)
{
	int	x;
	int	y;
	int	scr_x;
	int	scr_y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			scr_x = x * TILE_SIZE;
			scr_y = y * TILE_SIZE;
			blt(&backstage->empty, &map->tilemap, 0, 0, scr_x, scr_y + 12);
			if (map->data[y][x] == 'E' && map->collectibles > 0)
				blt(&backstage->exit1, &map->tilemap, 0, 0, scr_x, scr_y + 12);
			if (map->data[y][x] == 'E' && map->collectibles == 0)
				blt(&backstage->exit2, &map->tilemap, 0, 0, scr_x, scr_y + 12);
			if (map->data[y][x] == 'C')
				blt(&backstage->collectible, &map->tilemap, 0, 0, scr_x, scr_y);
			if (map->data[y][x] == '1')
			{
				blt(&backstage->wall, &map->tilemap, 0, 0, scr_x, scr_y);
				blt(&backstage->wall, &map->tilemap, 0, 32, scr_x, scr_y + 32);
			}
			x++;
		}
		y++;
	}
}
