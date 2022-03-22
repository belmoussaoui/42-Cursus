/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:57:59 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/22 17:36:11 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	draw_enemy(t_render *render, t_backstage *backstage, t_enemy *enemy,
			t_map *map)
{
	clear_sprite(&enemy->sprite);
	int count = (render->frames % 16000) / 1000;
	if (count > 7)
		count = 15 - count;
	blt_src(&backstage->enemy, &enemy->sprite, TILE_SIZE * count, 40 * enemy->direction);
	mlx_put_image_to_window(render->mlx, render->window, enemy->sprite.image,
		enemy->sprite.x + map->x, enemy->sprite.y + map->y - 8);
}

void	update_enemy(t_enemy *enemy, t_player *player, t_map *map)
{
	int	x;
	int	y;

	x = enemy->sprite.x / TILE_SIZE;
	y = enemy->sprite.y / TILE_SIZE;
	if (x < player->sprite.x / TILE_SIZE && map->data[y][x + 1] != '1')
	{
		enemy->direction = 2;
		enemy->sprite.x += 32;
	}
	else if (x > player->sprite.x / TILE_SIZE && map->data[y][x - 1] != '1')
	{
		enemy->direction = 1;
		enemy->sprite.x -= 32;
	}
	else if (y < player->sprite.y / TILE_SIZE && map->data[y + 1][x] != '1')
	{
		enemy->direction = 0;
		enemy->sprite.y += 32;
	}
	else if (y > player->sprite.y / TILE_SIZE && map->data[y- 1][x] != '1')
	{
		enemy->direction = 3;
		enemy->sprite.y -= 32;
	}
}

void	set_starting_position_enemy(t_enemy *enemy, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->data[y][x] == 'M')
			{
				enemy->sprite.x = x * TILE_SIZE;
				enemy->sprite.y = y * TILE_SIZE;
				break ;
			}
			x++;
		}
		y++;
	}
}