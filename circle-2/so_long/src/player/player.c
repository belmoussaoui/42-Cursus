/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:09:06 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/13 23:27:57 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include <stdio.h>

void	initialize_player(t_render *render, t_player *player)
{
	create_sprite(render, &player->sprite, 32, 32);
	player->sprite.x = 1;
	player->sprite.y = 1;
}

void	draw_player(t_render *render, t_player *player)
{
	int count = (render->frames % 2000) / 500;
	int x = player->sprite.x * TILE_SIZE;
	int y = player->sprite.y * TILE_SIZE;
	draw_sprite(render, &player->spriteset.image, &player->sprite.image, TILE_SIZE * count, 0);
	mlx_put_image_to_window(render->mlx, render->window, player->sprite.image.texture, x, y);
}