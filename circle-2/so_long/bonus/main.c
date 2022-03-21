/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:12:38 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/21 20:28:47 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	initialize_backstage(t_render *render, t_backstage *backstage)
{
	load_xpm_file(render, "assets/player.xpm", &backstage->player_idle);
	load_xpm_file(render, "assets/player_move.xpm", &backstage->player_move);
	load_xpm_file(render, "assets/empty.xpm", &backstage->empty);
	load_xpm_file(render, "assets/wall1.xpm", &backstage->wall1);
	load_xpm_file(render, "assets/wall2.xpm", &backstage->wall2);
	load_xpm_file(render, "assets/exit1.xpm", &backstage->exit1);
	load_xpm_file(render, "assets/exit2.xpm", &backstage->exit2);
	load_xpm_file(render, "assets/collectible.xpm", &backstage->collectible);
	load_xpm_file(render, "assets/enemy.xpm", &backstage->enemy);
}

void	initialize_enemy(t_render *render, t_enemy *enemy)
{
	create_sprite(render, &enemy->sprite, 32, 40);
}

void	initialize(t_game *game)
{
	initialize_render(&game->render);
	initialize_backstage(&game->render, &game->backstage);
	initialize_map(game, &game->render, &game->map);
	initialize_player(&game->render, &game->player);
	initialize_enemy(&game->render, &game->enemy);
	set_starting_position(&game->player, &game->map);
	draw_tilemap(&game->backstage, &game->map);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
		return (0);
	else
		game.map.name = argv[1];
	initialize(&game);
	run(&game);
}
