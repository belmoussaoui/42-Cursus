/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 23:11:24 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/22 18:57:32 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	handle_input(int keycode, t_game *game)
{
	int	x;
	int	y;

	if (game->player.anim_count >= 0)
		return (0);
	game_update(game);
	x = game->player.sprite.x / TILE_SIZE;
	y = game->player.sprite.y / TILE_SIZE;
	if (keycode == 53)
		exit_game(game);
	if (keycode == 1 && game->map.data[y + 1][x] != '1')
		update_move(game, &game->player, 0);
	else if (keycode == 0 && game->map.data[y][x - 1] != '1')
		update_move(game, &game->player, 1);
	else if (keycode == 2 && game->map.data[y][x + 1] != '1')
		update_move(game, &game->player, 2);
	else if (keycode == 13 && game->map.data[y - 1][x] != '1')
		update_move(game, &game->player, 3);
	x = game->player.sprite.x / TILE_SIZE;
	y = game->player.sprite.y / TILE_SIZE;
	return (0);
}

void	game_update(t_game *game)
{
	int	x;
	int	y;

	x = game->player.sprite.x / TILE_SIZE;
	y = game->player.sprite.y / TILE_SIZE;
	if (game->map.data[y][x] == 'C' && game->player.anim_count < 0)
	{
		game->map.collectibles--;
		game->map.data[y][x] = '0';
		draw_tilemap(&game->backstage, &game->map);
	}
	if (game->map.data[y][x] == 'E' && game->map.collectibles == 0
		&& game->player.anim_count < 0)
		exit_game(game);
	if (x == game->enemy.sprite.x / TILE_SIZE && y == game->enemy.sprite.y / TILE_SIZE
		&& game->player.anim_count < 0)
		exit_game(game);
	update_map(&game->map, &game->player);
	update_player(&game->player);
}

void	game_draw(t_game *game)
{
	char	*count;

	count = ft_itoa(game->player.move_count);
	mlx_clear_window(game->render.mlx, game->render.window);
	draw_map(&game->render, &game->map);
	draw_player(&game->render, &game->backstage, &game->player);
	draw_enemy(&game->render, &game->backstage, &game->enemy, &game->map);
	mlx_string_put(game->render.mlx, game->render.window, 10, 10, 0xffffff, count);
	free(count);
}

void	free_game(t_game *game)
{
	mlx_destroy_image(game->render.mlx, game->backstage.collectible.image);
	mlx_destroy_image(game->render.mlx, game->backstage.empty.image);
	mlx_destroy_image(game->render.mlx, game->backstage.exit1.image);
	mlx_destroy_image(game->render.mlx, game->backstage.exit2.image);
	mlx_destroy_image(game->render.mlx, game->backstage.player_idle.image);
	mlx_destroy_image(game->render.mlx, game->backstage.player_move.image);
	mlx_destroy_image(game->render.mlx, game->backstage.wall1.image);
	mlx_destroy_image(game->render.mlx, game->backstage.wall2.image);
	mlx_destroy_image(game->render.mlx, game->player.sprite.image);
	free_map(&game->render, &game->map);
}
