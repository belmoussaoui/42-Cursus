/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:40:48 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/14 20:37:56 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include <fcntl.h>

void initialize_collectibles(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	map->collectibles = 0;
	map->players = 0;
	map->exits = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->data[y][x] == 'C')
				map->collectibles++;
			if (map->data[y][x] == 'P')
			{
				map->players++;
				map->start_x = x;
				map->start_y = y;
			}
			if (map->data[y][x] == 'C')
				map->exits++;
			x++;
		}
		y++;
	}
}

void initialize_map(t_map *map)
{
	int fd = open("maps/map01.ber", O_RDONLY);
	char *line;
	char *res = malloc(1);
	res[0] = 0;
	map->height = 0;
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
	initialize_collectibles(map);
	//if (!check_rectangle(map) || !check_wall(map))
	//	exit(0);
}

int	check_rectangle(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->data[y][x])
			x++;
		if (x != map->width)
			return (0);
		y++;
	}
	return (1);
}

int	check_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		if (map->data[0][x] != '1')
			return (0);
		if (map->data[map->height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < map->height)
	{
		if (map->data[y][0] != '1')
			return (0);
		if (map->data[y][map->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}
