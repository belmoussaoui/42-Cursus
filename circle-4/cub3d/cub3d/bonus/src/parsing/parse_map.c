/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:18:46 by bperraud          #+#    #+#             */
/*   Updated: 2022/08/17 18:49:57 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	fill_map_dimensions(char *map_str, t_game *g)
{
	int	width;
	int	map_size;

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
	map_size = g->map.width * g->map.height * sizeof(int);
	g->map.data = x_malloc(map_size);
	g->map.object_map = x_malloc(map_size);
	g->map.visible_tiles = x_malloc(g->map.width
			* g->map.height * sizeof(bool));
	return (map_size);
}

static void	set_player(size_t i, size_t j, enum e_side direction, t_game *g)
{
	if (g->player.pos.x)
		exit_error("mutiple player position in map");
	g->player.pos = vector((double)j + 0.5, i - 0.1);
	g->player.dir.y = (direction == N) - (direction == S);
	g->player.dir.x = (direction == E) - (direction == W);
	g->player.plane.x = PLANE_LENGTH * g->player.dir.y;
	g->player.plane.y = -PLANE_LENGTH * g->player.dir.x;
	g->player.fov = 2 * atan(PLANE_LENGTH);
}

static void	parse_map_char(char map_char, int i, int j, t_game *g)
{
	t_door	*door;

	if (map_char == '0')
		g->map.data[i * g->map.width + j] = 0;
	else if (isascii_48(map_char) && g->walls[map_char - 49].img)
		g->map.data[i * g->map.width + j] = map_char - 48;
	else if (ft_strchr("NSWE", map_char))
	{
		g->map.data[i * g->map.width + j] = 0;
		set_player(i, j, get_direction(map_char), g);
	}
	else if (ft_strchr(SPACES, map_char))
		g->map.data[i * g->map.width + j] = -1;
	else
		exit_error("invalid character in map");
	if (map_char == ':')
	{
		door = x_calloc(1, sizeof(t_door));
		door->cell = (g->map.height - 1 - i) * g->map.width + j;
		door->ratio = 1;
		lst_add_front(&g->doors, new_node(door));
	}
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
	int	map_size;

	map_size = fill_map_dimensions(map_str, g);
	ft_memset(g->map.object_map, 0, map_size);
	ft_memset(g->map.visible_tiles, 0, g->map.width
		* g->map.height * sizeof(bool));
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
