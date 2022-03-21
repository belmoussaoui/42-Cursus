/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:32:11 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/21 01:55:29 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	update_move(t_player *player, int direction)
{
	player->direction = direction;
	player->move_count++;
	player->anim_count = 16;
	if (direction == 0)
		player->sprite.y += TILE_SIZE;
	if (direction == 1)
		player->sprite.x -= TILE_SIZE;
	if (direction == 2)
		player->sprite.x += TILE_SIZE;
	if (direction == 3)
		player->sprite.y -= TILE_SIZE;
	ft_putnbr_fd(player->move_count, 1);
	ft_putchar_fd('\n', 1);
}
