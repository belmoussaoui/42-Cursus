/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:18:46 by bperraud          #+#    #+#             */
/*   Updated: 2022/08/15 13:58:21 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_map_dimensions(char *map_str, t_game *g)
{
	int	width;

	width = 0;
	while (*map_str)
	{
		if (*map_str == '\n')
		{
			if (g->map.width < width)
				g->map.width = width;
			width = 0;
			g->map.height++;
		}
		else
			width++;
		map_str++;
	}
	g->map.height++;
}

static void	set_player(int i, int j, enum e_side direction, t_game *g)
{
	if (g->player.pos.x)
		exit_error("mutiple player position in map");
	g->player.pos = vector(j + 0.5, i - 0.5);
	g->player.dir.y = (direction == N) - (direction == S);
	g->player.dir.x = (direction == E) - (direction == W);
	g->player.plane.x = 0.66 * g->player.dir.y;
	g->player.plane.y = -0.66 * g->player.dir.x;
}

static void	parse_map_char(char map_char, int i, int j, t_game *g)
{
	if (map_char == '1')
		g->map.data[i * g->map.width + j] = 1;
	else if (map_char == '0')
		g->map.data[i * g->map.width + j] = 0;
	else if (ft_strchr("NSWE", map_char))
	{
		g->map.data[i * g->map.width + j] = 0;
		set_player(i, j, get_direction(map_char), g);
	}
	else if (ft_strchr(SPACES, map_char))
		g->map.data[i * g->map.width + j] = -1;
	else
		exit_error("invalid character in map");
}

static void	init_map_data(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->map.width * g->map.height)
	{
		g->map.data[i] = -1;
		i++;
	}
}

void	parse_map(char *map_str, t_game *g)
{
	int	i;
	int	j;

	fill_map_dimensions(map_str, g);
	g->map.data = x_malloc(g->map.width * g->map.height * sizeof(int));
	i = 0;
	init_map_data(g);
	while (i < g->map.height)
	{
		j = 0;
		while (*map_str != '\n' && *map_str)
		{
			parse_map_char(*map_str, i, j, g);
			j++;
			map_str++;
		}
			map_str += (*map_str == '\n');
		i++;
	}
	if (!g->player.pos.x)
		exit_error("no player position given in map");
}
