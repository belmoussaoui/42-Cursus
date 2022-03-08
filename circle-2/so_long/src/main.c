/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:12:38 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/08 12:30:26 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include <stdio.h>

t_sprite new_sprite(void *mlx, char *filepath)
{
	t_sprite sprite;
	sprite.image.ptr = mlx_xpm_file_to_image(mlx, filepath, &sprite.width, &sprite.height);
	return (sprite);
}

int	handle_input(int key, t_game *game)
{
	if (key == 124)
		game->mario.x += 16;
	else if (key == 123)
		game->mario.x -= 16;
	else if (key == 125)
		game->mario.y += 16;
	else if (key == 126)
		game->mario.y -= 16;
	return (0);
}

void game_update(t_game *game)
{
	(void) game;
}

void draw_mario(t_game *game, t_sprite mario)
{
	mlx_put_image_to_window(game->mlx, game->window, mario.image.ptr, mario.x, mario.y);
}

void game_render(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	draw_mario(game, game->mario);
}

int game_loop(t_game *game)
{
	static int frames;
	float delta_time;

	delta_time = 10000 / FPS;
	while (game->accumulator >= delta_time)
	{
		//game_input(game);
		game_update(game);
		game_render(game);
		game->accumulator -= delta_time;
	}
	game->accumulator++;
	frames++;
	return (0);
}

int main(void)
{
	t_game game;

	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 256, 240, "so_long");

	game.mario = new_sprite(game.mlx, "./assets/mario.xpm");

	mlx_key_hook(game.window, *handle_input, &game);
	mlx_loop_hook(game.mlx, *game_loop, &game);
	mlx_loop(game.mlx);
}