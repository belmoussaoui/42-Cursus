/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:36:45 by bperraud          #+#    #+#             */
/*   Updated: 2022/09/29 10:27:53 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# define WALK_START 0
# define WALK_END 3
# define SHOOT_START 4
# define SHOOT_END 6
# define SHOT_START 7
# define SHOT_END 7
# define DIE_START 8
# define DIE_END 10

# include "cub3d.h"

void	create_enemy(t_game *game, double x, double y, char *path);

enum e_enemy
{
	WALK,
	SHOOT,
	SHOT,
	DIE
};

typedef struct s_enemy
{
	t_sprite		s;
	enum e_enemy	state;
	int				hp;
}	t_enemy;

#endif