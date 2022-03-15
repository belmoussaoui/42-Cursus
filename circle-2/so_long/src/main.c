/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:12:38 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/15 18:34:58 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "stdio.h"

void	load_assets(t_game *game)
{
	load_texture(&game->render, "assets/player.xpm", &game->player.spriteset);
	load_texture(&game->render, "assets/empty.xpm", &game->empty);
	load_texture(&game->render, "assets/wall.xpm", &game->wall);
	load_texture(&game->render, "assets/exit.xpm", &game->exit);
	load_texture(&game->render, "assets/collectible.xpm", &game->collectible);
}

void	game_update(t_game *game)
{
	(void) game;
	//printf("udpade\n");
}

void	game_draw(t_game *game)
{
	game->map.display_x = WIDTH / 2 - (game->player.sprite.x * 32) - 16;
	game->map.display_y = HEIGHT / 2 - (game->player.sprite.y * 32) - 16;
	mlx_clear_window(game->render.mlx, game->render.window);
	int i = 0;
	while (i < game->map.height)
	{
		int j = 0;
		while (j < game->map.width)
		{
			mlx_put_image_to_window(game->render.mlx, game->render.window, game->empty.image.texture, j * 32 + game->map.display_x, i * 32 + game->map.display_y);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < game->map.height)
	{
		int j = 0;
		while (j < game->map.width)
		{
			if (game->map.data[i][j] == 'E')
			 	mlx_put_image_to_window(game->render.mlx, game->render.window, game->exit.image.texture, j * 32 + game->map.display_x, i * 32 + 12 + game->map.display_y);
			if (game->map.data[i][j] == 'C')
			 	mlx_put_image_to_window(game->render.mlx, game->render.window, game->collectible.image.texture, j * 32 + game->map.display_x, i * 32 + game->map.display_y);
			if (game->map.data[i][j] == '1')
				mlx_put_image_to_window(game->render.mlx, game->render.window, game->wall.image.texture, j * 32 + game->map.display_x, i * 32 + game->map.display_y);
			j++;
		}
		i++;
	}
	draw_player(&game->render, &game->player, &game->map);
}

void initialize(t_game *game)
{
	initialize_map(&game->map);
	initialize_player(&game->render, &game->player, game->map.start_x, game->map.start_y);
	load_assets(game);
}

int main(void)
{
	t_game	game;
	
	play(&game);
}
