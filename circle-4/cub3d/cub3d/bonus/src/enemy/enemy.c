/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:21:53 by bperraud          #+#    #+#             */
/*   Updated: 2022/09/29 10:28:13 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	add_enemy(t_game *game, t_enemy *enemy)
{
	int	i;
	int	j;

	i = 0;
	while (game->list_sprite[i])
		i++;
	game->list_sprite[i] = &enemy->s;
	j = 0;
	while (game->list_enemy[j])
		j++;
	game->list_enemy[j] = enemy;
}

void	create_enemy(t_game *game, double x, double y, char *path)
{
	t_enemy		*enemy;
	int			i;

	i = 0;
	enemy = x_malloc(sizeof(t_enemy));
	enemy->hp = 100;
	enemy->s.is_collect = 0;
	enemy->s.collect_action = NULL;
	enemy->s.x = x;
	enemy->s.y = y;
	enemy->s.t = get_img_from_xpm(game->mlx, path);
	bound_start(&enemy->s, enemy->s.t);
	enemy->s.image = 3;
	add_enemy(game, enemy);
}
