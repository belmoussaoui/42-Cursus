/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:16:55 by vrogiste          #+#    #+#             */
/*   Updated: 2022/09/07 20:29:08 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_pos(t_game *g, t_vector *pos, t_vector *np)
{
	if (((!g->map.data[(int)pos->y * g->map.width + (int)np->x]
				&&g->map.object_map[(int)pos->y * g->map.width + (int)np->x]
				!= 1)
			|| can_pass_door((int)pos->y * g->map.width + (int)np->x, g))
		&& (np->x - (int)np->x < 0.9999
			||!g->map.data[(int)pos->y * g->map.width + (int)np->x + 1]
			||g->map.data[(int)pos->y * g->map.width + (int)np->x + 1] == 10)
		&& (np->x - (int)np->x > 0.0001
			||!g->map.data[(int)pos->y * g->map.width + (int)np->x - 1]
			||g->map.data[(int)pos->y * g->map.width + (int)np->x - 1] == 10))
		pos->x = np->x;
	if (((!g->map.data[(int)np->y * g->map.width + (int)pos->x]
				&& g->map.object_map[(int)np->y * g->map.width + (int)pos->x]
				!= 1)
			|| can_pass_door((int)np->y * g->map.width + (int)pos->x, g))
		&& (np->y - (int)np->y < 0.9999
			||!g->map.data[((int)np->y + 1) * g->map.width + (int)pos->x]
			||g->map.data[((int)np->y + 1) * g->map.width + (int)pos->x] == 10)
		&& (np->y - (int)np->y > 0.0001
			||!g->map.data[((int)np->y - 1) * g->map.width + (int)pos->x]
			||g->map.data[((int)np->y - 1) * g->map.width + (int)pos->x] == 10))
		pos->y = np->y;
}

static void	translate_rl(t_game *g, t_vector *pos, t_vector *dir)
{
	t_vector	np;

	if (g->state.right)
	{
		np = vector(pos->x + dir->y * MOVE_SPEED, pos->y - dir->x * MOVE_SPEED);
		update_pos(g, pos, &np);
	}
	if (g->state.left)
	{
		np = vector(pos->x - dir->y * MOVE_SPEED, pos->y + dir->x * MOVE_SPEED);
		update_pos(g, pos, &np);
	}
}

void	translate_cam(t_game *g)
{
	t_vector	*pos;
	t_vector	dir;
	t_vector	np;

	pos = &g->player.pos;
	dir = g->player.dir;
	if (g->state.up)
	{
		np = vector(pos->x + dir.x * MOVE_SPEED, pos->y + dir.y * MOVE_SPEED);
		update_pos(g, pos, &np);
	}
	if (g->state.down)
	{
		np = vector(pos->x - dir.x * MOVE_SPEED, pos->y - dir.y * MOVE_SPEED);
		update_pos(g, pos, &np);
	}
	translate_rl(g, pos, &dir);
}

void	rotate_cam(t_game *g)
{
	if (g->state.r_left)
	{
		g->player.dir = vector_rotate(g->player.dir, ROT_SPEED);
		g->player.plane = vector_rotate(g->player.plane, ROT_SPEED);
	}
	if (g->state.r_right)
	{
		g->player.dir = vector_rotate(g->player.dir, -ROT_SPEED);
		g->player.plane = vector_rotate(g->player.plane, -ROT_SPEED);
	}
	if (g->state.m_left)
	{
		g->player.dir = vector_rotate(g->player.dir, g->state.m_left * MRS);
		g->player.plane = vector_rotate(g->player.plane, g->state.m_left * MRS);
		g->state.m_left = 0;
	}
	if (g->state.m_right)
	{
		g->player.dir = vector_rotate(g->player.dir, -g->state.m_right * MRS);
		g->player.plane = vector_rotate(g->player.plane,
				-g->state.m_right * MRS);
		g->state.m_right = 0;
	}
}
