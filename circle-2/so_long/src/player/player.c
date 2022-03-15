/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:09:06 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/15 16:57:51 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include <stdio.h>

void	initialize_player(t_render *render, t_player *player, int x, int y)
{
	create_sprite(render, &player->sprite, 32, 32);
	player->moves = 0;
	player->direction = 0;
	player->sprite.x = x;
	player->sprite.y = y;
}

void	draw_player(t_render *render, t_player *player, t_map *map)
{
	int count = (render->frames % 2000) / 500;
	int x = player->sprite.x * TILE_SIZE + map->display_x;
	int y = player->sprite.y * TILE_SIZE + map->display_y;
	draw_sprite(render, &player->spriteset.image, &player->sprite.image, TILE_SIZE * count, TILE_SIZE * player->direction);
	mlx_put_image_to_window(render->mlx, render->window, player->sprite.image.texture, x, y);
}
