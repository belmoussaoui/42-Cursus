/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:03:16 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/17 18:34:43 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h>

int	handle_input(int keycode, t_game *game)
{
	int	x;
	int	y;

	if (game->map.display_x != game->map.x
		|| game->map.display_y != game->map.y)
		return (0);
	x = game->player.sprite.x;
	y = game->player.sprite.y;
	if (keycode == 124 && game->map.data[y][x + 1] != '1')
	{
		game->render.frames = 0;
		game->player.sprite.x++;
		game->player.direction = 2;
		game->player.moves++;
		ft_putnbr_fd(game->player.moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (keycode == 123 && game->map.data[y][x - 1] != '1')
	{
		game->render.frames = 0;
		game->player.sprite.x--;
		game->player.direction = 1;
		game->player.moves++;
		ft_putnbr_fd(game->player.moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (keycode == 125 && game->map.data[y + 1][x] != '1')
	{
		game->render.frames = 0;
		game->player.sprite.y++;
		game->player.direction = 0;
		game->player.moves++;
		ft_putnbr_fd(game->player.moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (keycode == 126 && game->map.data[y - 1][x] != '1')
	{
		game->render.frames = 0;
		game->player.moves++;
		game->player.direction = 3;
		game->player.sprite.y--;
		ft_putnbr_fd(game->player.moves, 1);
		ft_putchar_fd('\n', 1);
	}
	if (game->map.data[y][x] == 'C')
	{
		game->map.data[y][x] = '0';
		game->map.collectibles--;
	}
	x = game->player.sprite.x;
	y = game->player.sprite.y;
	if (game->map.data[y][x] == 'E' && game->map.collectibles == 0)
	{
		printf("ok\n");
		exit(0);
	}
	return (0);
}
