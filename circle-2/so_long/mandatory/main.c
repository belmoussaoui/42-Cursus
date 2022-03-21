/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:12:38 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/21 02:10:02 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	initialize_backstage(t_render *render, t_backstage *backstage)
{
	load_xpm_file(render, "assets/player.xpm", &backstage->player_idle);
	load_xpm_file(render, "assets/player_move.xpm", &backstage->player_move);
	load_xpm_file(render, "assets/empty.xpm", &backstage->empty);
	load_xpm_file(render, "assets/wall.xpm", &backstage->wall);
	load_xpm_file(render, "assets/exit1.xpm", &backstage->exit1);
	load_xpm_file(render, "assets/exit2.xpm", &backstage->exit2);
	load_xpm_file(render, "assets/collectible.xpm", &backstage->collectible);
}

void	initialize(t_game *game)
{
	initialize_render(&game->render);
	initialize_map(&game->render, &game->map);
	initialize_player(&game->render, &game->player);
	initialize_backstage(&game->render, &game->backstage);
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
