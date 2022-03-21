/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:09:06 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/21 02:17:56 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include <stdio.h>

void	initialize_player(t_render *render, t_player *player)
{
	player->anim_count = -1;
	create_sprite(render, &player->sprite, 32, 32);
}

void	set_starting_position(t_player *player, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->data[y][x] == 'P')
			{
				player->sprite.x = x * TILE_SIZE;
				player->sprite.y = y * TILE_SIZE;
				break ;
			}
			x++;
		}
		y++;
	}
	map->x = WIDTH / 2 - player->sprite.x - TILE_SIZE / 2;
	map->y = HEIGHT / 2 - player->sprite.y - TILE_SIZE / 2;
}

void	update_player(t_player *player)
{
	if (player->anim_count >= 0)
		player->anim_count--;
}

void	draw_player(t_render *render, t_backstage *backstage, t_player *player)
{
	int	count;

	clear_sprite(&player->sprite);
	if (player->anim_count >= 0)
	{
		count = 0;
		if (player->anim_count < 6)
			count = 3;
		else if (player->anim_count < 10)
			count = 2;
		else if (player->anim_count < 14)
			count = 1;
		blt(&backstage->player_move, &player->sprite,
			TILE_SIZE * count, TILE_SIZE * player->direction, 0, 0);
	}
	else
	{
		count = (render->frames % 4000) / 1000;
		blt(&backstage->player_idle, &player->sprite,
			TILE_SIZE * count, TILE_SIZE * player->direction, 0, 0);
	}
	mlx_put_image_to_window(render->mlx, render->window, player->sprite.image,
		WIDTH / 2 - TILE_SIZE / 2, HEIGHT / 2 - TILE_SIZE / 2);
}
