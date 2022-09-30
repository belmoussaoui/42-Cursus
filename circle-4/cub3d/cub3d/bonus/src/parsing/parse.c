/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:54:35 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/05 11:54:35 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

enum e_side	get_direction(char c)
{
	return ((c == 'N') * N + (c == 'S') * S + (c == 'W') * W + (c == 'E') * E);
}

static void	invert_map_rows(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->map.height / 2)
	{
		j = 0;
		while (j < g->map.width)
		{
			swap_int(
				&g->map.data[i * g->map.width + j],
				&g->map.data[(g->map.height - 1 - i) * g->map.width + j]);
			j++;
		}
		i++;
	}
	g->player.pos.y = g->map.height - 1 - g->player.pos.y;
}

void	parse(int argc, char **argv, t_game *game)
{
	int		fd;
	char	*map_str;

	if (argc != 2)
		exit_error("invalid number of arguments");
	fd = open(argv[1], O_DIRECTORY);
	if (fd != -1)
		exit_error("the map is a folder");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	parse_textures(game, fd);
	map_str = get_map_str(fd);
	parse_map(map_str, game);
	check_map(game);
	invert_map_rows(game);
	parse_sprite(game, fd);
	free(map_str);
	close(fd);
}
