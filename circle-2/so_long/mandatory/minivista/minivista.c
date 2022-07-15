/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minivista.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:18:26 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/13 21:42:43 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	exit_game(t_game *game)
{
	t_render	render;

	render = game->render;
	free_game(game);
	mlx_destroy_window(render.mlx, render.window);
	exit(0);
	return (0);
}

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

void	initialize_render(t_render *render)
{
	render->mlx = mlx_init();
	render->window = mlx_new_window(render->mlx, WIDTH, HEIGHT, TITLE);
}

void	run(t_game *game)
{
	t_render	render;

	render = game->render;
	mlx_loop_hook(render.mlx, *game_loop, game);
	mlx_key_hook(render.window, *handle_input, game);
	mlx_hook(render.window, 17, 0, exit_game, game);
	mlx_loop(render.mlx);
}
