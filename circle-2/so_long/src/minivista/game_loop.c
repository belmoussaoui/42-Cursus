/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:25:54 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/17 18:43:43 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	game_loop(t_game *game)
{
	float	delta_time;

	delta_time = 10000 / FPS;
	if (game->render.accumulator >= delta_time)
	{
		game_update(game);
		game_draw(game);
		game->render.accumulator -= delta_time;
	}
	game->render.accumulator++;
	game->render.frames++;
	return (0);
}
