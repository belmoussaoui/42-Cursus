/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:12:38 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/10 19:25:19 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

t_sprite new_sprite(void *mlx, char *filepath)
{
	t_sprite sprite;
	sprite.image.ptr = mlx_xpm_file_to_image(mlx, filepath, &sprite.width, &sprite.height);
	return (sprite);
}

int	handle_input(int key, t_game *game)
{
	if (key == 124 && game->map.data[game->mario.y / 16][(game->mario.x + 16) / 16] != '1')
		game->mario.x += 16;
	else if (key == 123 && game->map.data[game->mario.y / 16][(game->mario.x - 16) / 16] != '1')
		game->mario.x -= 16;
	else if (key == 125 && game->map.data[(game->mario.y + 16) / 16][(game->mario.x ) / 16] != '1')
		game->mario.y += 16;
	else if (key == 126 && game->map.data[(game->mario.y - 16) / 16][(game->mario.x) / 16] != '1')
		game->mario.y -= 16;
	return (0);
}

void draw_map(t_game *game)
{
	int i = 0;
	printf("%d %d\n", game->map.height, game->map.width);
	while (i < game->map.height)
	{
		int j = 0;
		while (j < game->map.width)
		{
			if (game->map.data[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall.image.ptr, j * 16, i * 16);
			else
				mlx_put_image_to_window(game->mlx, game->window, game->empty.image.ptr, j * 16, i * 16);
			j++;
		}
		i++;
	}
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
	draw_map(game);
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

void load_map(t_game *game)
{
	t_map *map = &game->map;
	int fd = open("maps/map01.ber", O_RDONLY);
	char *line;
	char *res = malloc(1);
	res[0] = 0;
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->height++;
		res = ft_strjoin(res, line);
		free(line);
	}
	close(fd);
 	map->width = 0;
	while (res[map->width] != '\n')
		map->width++;
	map->data = ft_split(res, '\n');
	
	//printf("%d\n", game->map.width);
}




// void initialize_map(t_game *game)
// {
// 	// int *map = malloc(sizeof(int) * 25);
// 	// game->map.data = map;
// }

int main(void)
{
	t_game game;
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 256, 240, "so_long");
	game.mario = new_sprite(game.mlx, "./assets/player.xpm");
	game.mario.x = 32;
	game.mario.y = 32;
	game.wall = new_sprite(game.mlx, "./assets/wall.xpm");
	game.empty = new_sprite(game.mlx, "./assets/empty.xpm");

	load_map(&game);
	//initialize_map(&game);
	draw_mario(&game, game.mario);

	mlx_key_hook(game.window, *handle_input, &game);
	mlx_loop_hook(game.mlx, *game_loop, &game);
	mlx_loop(game.mlx);
}