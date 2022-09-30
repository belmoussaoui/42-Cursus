/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:33:01 by bperraud          #+#    #+#             */
/*   Updated: 2022/09/30 10:33:59 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	anim_gun(t_game *game)
{
	int			i;
	t_gun		*gun;

	i = 0;
	gun = game->list_active_gun[game->active_gun];
	if (gun)
	{
		if (gun->ammo || gun->is_knife)
		{
			play_sound(gun->path_sound, game);
			gun->ammo--;
			if (!gun->image)
				gun->image += 1;
		}
		else
		{
			if (game->list_active_gun[!game->active_gun]
				&& game->list_active_gun[!game->active_gun]->ammo)
				game->active_gun = !game->active_gun;
			else
				game->list_active_gun[0] = game->list_gun[KNIFE];
		}
	}
}

void	switch_gun(t_game *game)
{
	if (game->list_active_gun[1]
		&& game->list_active_gun[!game->active_gun]->ammo)
	{
		play_sound("weapons/change.wav", game);
		game->active_gun = !game->active_gun;
	}
}

void	render_gun(t_game *game)
{
	t_gun	*gun;

	gun = game->list_active_gun[game->active_gun];
	if (gun)
	{
		if (gun->image == gun->s.t.width / gun->s.t.height)
			gun->image = 0;
		else
		{
			draw_sprite(game, &gun->s, &gun->s.t, gun->image);
			if (gun->image)
				gun->image += 0.5;
		}
	}
}
