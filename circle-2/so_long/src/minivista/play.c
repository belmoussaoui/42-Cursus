/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:18:26 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/13 23:15:44 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	close_game(t_game *game)
{
	t_render render;
	
	render = game->render;
	mlx_destroy_window(render.mlx, render.window);
	exit(0);
	return (0);
}

void create_hook(t_game *game)
{
	t_render render;
	
	render = game->render;
	mlx_loop_hook(render.mlx, *game_loop, game);
	mlx_key_hook(render.window, *handle_input, game);
	mlx_hook(render.window, 17, 0, close_game, game);
	mlx_loop(render.mlx);
}
#include <stdio.h>
void play(t_game *game)
{
	t_render *render;
	int w;
	int h;

	render = &game->render;
	render->frames = 0;
	render->mlx = mlx_init();
	render->window = mlx_new_window(render->mlx, WIDTH, HEIGHT, "minivista");
	initialize(game);
	mlx_xpm_file_to_image(render->mlx, "./assets/player.xpm", &w, &h);
	create_hook(game);
}