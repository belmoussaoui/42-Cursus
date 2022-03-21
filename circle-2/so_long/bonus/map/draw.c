/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:51:58 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/21 17:29:47 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	draw_tile(t_render *render, t_sprite *sprite, int x, int y)
{
	mlx_put_image_to_window(render->mlx, render->window, sprite->image, x, y);
}

void	draw_map(t_render *render, t_map *map)
{
	mlx_put_image_to_window(render->mlx, render->window, map->tilemap.image,
		map->x, map->y);
}

void	draw_wall(t_backstage *backstage, t_map *map, int x, int y)
{
	blt_dst(&backstage->wall1, &map->tilemap, x, y);
	blt_dst(&backstage->wall2, &map->tilemap, x, y + 32);
}

void	draw_tilemap(t_backstage *backstage, t_map *map)
{
	int	x;
	int	y;
	int	scr_x;
	int	scr_y;

	y = -1;
	while (++y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			scr_x = x * TILE_SIZE;
			scr_y = y * TILE_SIZE;
			blt_dst(&backstage->empty, &map->tilemap, scr_x, scr_y + 12);
			if (map->data[y][x] == 'E' && map->collectibles > 0)
				blt_dst(&backstage->exit1, &map->tilemap, scr_x, scr_y + 12);
			if (map->data[y][x] == 'E' && map->collectibles == 0)
				blt_dst(&backstage->exit2, &map->tilemap, scr_x, scr_y + 12);
			if (map->data[y][x] == 'C')
				blt_dst(&backstage->collectible, &map->tilemap, scr_x, scr_y);
			if (map->data[y][x] == '1')
				draw_wall(backstage, map, scr_x, scr_y);
			x++;
		}
	}
}
