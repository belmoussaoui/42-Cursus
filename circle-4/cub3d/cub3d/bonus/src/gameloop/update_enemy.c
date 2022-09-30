/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:57:03 by vrogiste          #+#    #+#             */
/*   Updated: 2022/09/29 17:52:16 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_enemy_pos(t_game *g, t_enemy *enemy)
{
	t_vector	v;
	t_vector	dir;
	t_vector	np;

	v = vector(g->player.pos.x - enemy->s.x, g->player.pos.y - enemy->s.y);
	dir = vector_normalize(v);
	if (vector_norme(v) > 1.3)
	{
		enemy->state = WALK;
		np = vector(
				enemy->s.x + dir.x * (MOVE_SPEED * 3),
				enemy->s.y + dir.y * (MOVE_SPEED * 3));
		g->map.object_map[(int)enemy->s.y * g->map.width + (int)enemy->s.x] = 0;
		if (!g->map.data[(int)enemy->s.y * g->map.width + (int)np.x]
			|| can_pass_door((int)enemy->s.y * g->map.width + (int)np.x, g))
			enemy->s.x = np.x;
		if (!g->map.data[(int)np.y * g->map.width + (int)enemy->s.x]
			|| can_pass_door((int)np.y * g->map.width + (int)enemy->s.x, g))
			enemy->s.y = np.y;
		g->map.object_map[(int)np.y * g->map.width + (int)enemy->s.x] = 1;
	}
	else
		ennemy_shot(g, enemy);
}

static int	start(t_enemy *enemy)
{
	return (
		(enemy->state == WALK) * WALK_START
		+ (enemy->state == SHOOT) * SHOOT_START
		+ (enemy->state == SHOT) * SHOT_START
		+ (enemy->state == DIE) * DIE_START);
}

static int	end(t_enemy *enemy)
{
	return (
		(enemy->state == WALK) * WALK_END
		+ (enemy->state == SHOOT) * SHOOT_END
		+ (enemy->state == SHOT) * SHOT_END
		+ (enemy->state == DIE) * DIE_END);
}

static void	update_enemy_animation(t_enemy *e, t_game *g)
{
	if (e->hp <= 0)
		e->state = DIE;
	else if (g->state.shoot
		&& g->map.visible_tiles[((int)(e->s.y) * g->map.width + (int)(e->s.x))])
	{
		if (fabs(e->s.angle) < M_PI / 16)
		{
			e->state = SHOT;
			e->hp -= 20;
		}
	}
	else
		update_enemy_pos(g, e);
	if (e->s.image < start(e))
		e->s.image = start(e);
	if (e->s.image == DIE_END)
		g->map.object_map[(int)e->s.y * g->map.width + (int)e->s.x] = 0;
	if (e->s.image != DIE_END)
		e->s.image += 1;
	if (e->s.image > end(e))
		e->s.image = start(e);
}

void	update_enemy(t_game *g)
{
	static int	accu;
	int			i;

	if (!(accu % 10))
	{
		i = 0;
		while (i < ENEMY_MAX)
		{
			if (g->list_enemy[i])
				update_enemy_animation(g->list_enemy[i], g);
			i++;
		}
		g->state.shoot = 0;
	}
	accu++;
}
