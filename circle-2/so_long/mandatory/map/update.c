/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:16:10 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/20 19:40:53 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	update_map(t_map *map, t_player *player)
{
	int	scroll_speed;
	int	x;
	int	y;

	x = WIDTH / 2 - player->sprite.x - TILE_SIZE / 2;
	y = HEIGHT / 2 - player->sprite.y - TILE_SIZE / 2;
	scroll_speed = 2;
	if (map->x < x)
		map->x += scroll_speed;
	if (map->x > x)
		map->x -= scroll_speed;
	if (map->y < y)
		map->y += scroll_speed;
	if (map->y > y)
		map->y -= scroll_speed;
}
