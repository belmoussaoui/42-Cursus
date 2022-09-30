/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:33:27 by bel-mous          #+#    #+#             */
/*   Updated: 2022/08/17 13:11:50 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_door_opened(t_game *g)
{
	int			x;
	int			y;
	t_vector	dir;
	size_t		width;
	uintptr_t	door;

	x = g->player.pos.x;
	y = g->player.pos.y;
	dir = g->player.dir;
	width = g->map.width;
	door = 0;
	door |= (uintptr_t)get_door((y + 1) * width + x, g) * !door * (dir.y > 0);
	door |= (uintptr_t)get_door((y - 1) * width + x, g) * !door * (dir.y < 0);
	door |= (uintptr_t)get_door(y * width + (x - 1), g) * !door * (dir.x < 0);
	door |= (uintptr_t)get_door(y * width + (x + 1), g) * !door * (dir.x > 0);
	if (door)
	{
		((t_door *)door)->opened = !((t_door *)door)->opened;
		if (!((t_door *)door)->opened)
			play_sound("Interaction/doors/door2_close.wav", g);
		else
			play_sound("Interaction/doors/door2_open.wav", g);
	}
}

int	key_down(int code, t_game *game)
{
	if (code == K_W || code == K_UP)
		game->state.up = true;
	else if (code == K_S || code == K_DOWN)
		game->state.down = true;
	else if (code == K_A)
		game->state.left = true;
	else if (code == K_D)
		game->state.right = true;
	else if (code == K_LEFT)
		game->state.r_left = true;
	else if (code == K_RIGHT)
		game->state.r_right = true;
	else if (code == K_E)
		update_door_opened(game);
	else if (code == K_SPACE)
		switch_gun(game);
	else if (code == K_CTRL)
	{
		anim_gun(game);
		game->state.shoot = true;
	}
	return (0);
}

int	key_release(int code, t_game *game)
{
	if (code == K_W || code == K_UP)
		game->state.up = false;
	else if (code == K_S || code == K_DOWN)
		game->state.down = false;
	else if (code == K_A)
		game->state.left = false;
	else if (code == K_D)
		game->state.right = false;
	else if (code == K_LEFT)
		game->state.r_left = false;
	else if (code == K_RIGHT)
		game->state.r_right = false;
	else if (code == K_ESC)
		quit(game);
	return (0);
}

int	mouse_hook(int x, int y, t_game *game)
{
	(void) y;
	if (x < 400)
		game->state.m_left = 400 - x;
	else if (x > 400)
		game->state.m_right = x - 400;
	mouse_move(game, 500, 500);
	return (0);
}
