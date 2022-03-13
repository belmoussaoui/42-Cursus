/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:03:16 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/13 23:23:51 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h>

int	handle_input(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->player.sprite.x;
	y = game->player.sprite.y;
	if (keycode == 124 && game->map.data[y][x + 1] != '1')
		game->player.sprite.x++;
	else if (keycode == 123 && game->map.data[y][x - 1] != '1')
		game->player.sprite.x--;
	else if (keycode == 125 && game->map.data[y + 1][x] != '1')
		game->player.sprite.y++;
	else if (keycode == 126 && game->map.data[y - 1][x] != '1')
		game->player.sprite.y--;
	if (game->map.data[y][x] == 'C')
		game->map.data[y][x] = '0';
	return (0);
}