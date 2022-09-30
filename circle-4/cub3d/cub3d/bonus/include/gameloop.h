/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:32:35 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/09 13:22:08 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMELOOP_H
# define GAMELOOP_H

# include "cub3d.h"

/* door */
t_door	*get_door(int cell, t_game *g);
bool	can_pass_door(int cell, t_game *g);

/* gameloop */
int		game_loop(t_game *game);
void	title_update(t_game *game);

/* update_cam */
void	translate_cam(t_game *game);
void	rotate_cam(t_game *game);

/* update_enemy */
void	update_enemy(t_game *g);

/* enemy_shot */
void	ennemy_shot(t_game *g, t_enemy *enemy);

#endif
