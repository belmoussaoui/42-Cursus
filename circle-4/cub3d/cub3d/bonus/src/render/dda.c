/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:01:48 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/17 15:55:34 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_vector	get_init_side_dist(t_vector delta_dist, t_ray *ray, t_game *g)
{
	t_vector	pos;
	t_vector	side_dist;

	pos = g->player.pos;
	if (ray->dir.x < 0)
		side_dist.x = (pos.x - ray->cell % g->map.width) * delta_dist.x;
	else
		side_dist.x = (ray->cell % g->map.width + 1.0 - pos.x) * delta_dist.x;
	if (ray->dir.y < 0)
		side_dist.y = (pos.y - ray->cell / g->map.width) * delta_dist.y;
	else
		side_dist.y = (ray->cell / g->map.width + 1.0 - pos.y) * delta_dist.y;
	return (side_dist);
}

static bool	compute_cell_we(
	t_vector *side_dist,
	t_vector delta_dist,
	t_ray *ray,
	t_game *g)
{
	double	wall_x;

	side_dist->x += delta_dist.x;
	ray->cell += -2 * (ray->dir.x < 0) + 1;
	ray->side = W * (ray->dir.x <= 0) + E * (ray->dir.x > 0);
	if (g->map.data[ray->cell] == 10)
	{
		if (side_dist->x - delta_dist.x / 2 < side_dist->y)
		{
			wall_x = g->player.pos.y
				+ (side_dist->x - delta_dist.x + delta_dist.x / 2) * ray->dir.y;
			wall_x -= floor((wall_x));
			if (wall_x < get_door(ray->cell, g)->ratio)
			{
				side_dist->x += delta_dist.x / 2;
				return (true);
			}
		}
	}
	return (false);
}

static bool	compute_cell_ns(
	t_vector *side_dist,
	t_vector delta_dist,
	t_ray *ray,
	t_game *g)
{
	double	wall_x;

	side_dist->y += delta_dist.y;
	ray->cell += -2 * g->map.width * (ray->dir.y < 0) + g->map.width;
	ray->side = N * (ray->dir.y >= 0) + S * (ray->dir.y < 0);
	if (g->map.data[ray->cell] == 10)
	{
		if (side_dist->y - delta_dist.y / 2 < side_dist->x)
		{
			wall_x = g->player.pos.x
				+ (side_dist->y - delta_dist.y + delta_dist.y / 2) * ray->dir.x;
			wall_x -= floor((wall_x));
			if (wall_x < get_door(ray->cell, g)->ratio)
			{
				side_dist->y += delta_dist.y / 2;
				return (true);
			}
		}
	}
	return (false);
}

void	dda(t_ray *ray, t_game *g)
{
	t_vector	delta_dist;
	t_vector	side_dist;
	bool		hit;

	ray->cell = (int)g->player.pos.y * g->map.width + (int)g->player.pos.x;
	delta_dist = vector(1 / fabs(ray->dir.x), 1 / fabs(ray->dir.y));
	side_dist = get_init_side_dist(delta_dist, ray, g);
	hit = false;
	while (!hit)
	{
		if (side_dist.x < side_dist.y)
			hit = compute_cell_we(&side_dist, delta_dist, ray, g);
		else
			hit = compute_cell_ns(&side_dist, delta_dist, ray, g);
		hit |= (g->map.data[ray->cell] && g->map.data[ray->cell] != 10);
		if (g->map.object_map[ray->cell])
			g->map.visible_tiles[ray->cell] = true;
	}
	ray->dist = side_dist.y - delta_dist.y;
	if (ray->side % 2)
		ray->dist = side_dist.x - delta_dist.x;
}
