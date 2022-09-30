/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_shot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:50:46 by jboumal           #+#    #+#             */
/*   Updated: 2022/09/29 22:35:03 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ennemy_shot(t_game *g, t_enemy *enemy)
{
	enemy->state = SHOOT;
	g->player_hp -= 3;
	if (g->player_hp <= 0)
		quit(g);
}
