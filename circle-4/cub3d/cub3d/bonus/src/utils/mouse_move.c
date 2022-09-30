/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:38:45 by jboumal           #+#    #+#             */
/*   Updated: 2022/08/23 12:32:18 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mouse_hook(t_game *game)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(game->mlx, game->window, &x, &y);
	if (x < 400)
		game->state.m_left = 400 - x;
	else if (x > 400)
		game->state.m_right = x - 400;
	mouse_move(game, 400, 400);
}

int	mouse_hide(t_game *game)
{
	if (LINUX)
		mlx_mouse_hide(game->mlx, game->window);
	else
		mac_mouse_hide();
	return (0);
}

int	mouse_move(t_game *game, int x, int y)
{
	if (LINUX)
		mlx_mouse_move(game->mlx, game->window, x, y);
	else
		mac_mouse_move(x, y);
	return (0);
}
