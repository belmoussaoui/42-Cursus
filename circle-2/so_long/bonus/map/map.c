/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:40:48 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/21 17:59:58 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	initialize_collectibles(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->data[y][x] == 'C')
				map->collectibles++;
			if (map->data[y][x] == 'P')
				map->players++;
			if (map->data[y][x] == 'E')
				map->exits++;
			x++;
		}
		y++;
	}
}

void	initialize_size(t_map *map)
{
	while (map->data[map->height])
		map->height++;
	if (map->height == 0)
		return ;
	while (map->data[0][map->width])
		map->width++;
}

void	initialize_data(t_map *map)
{
	int		fd;
	char	*data;
	char	*data_copy;
	char	*line;

	fd = open(map->name, O_RDONLY);
	data = ft_calloc(1, sizeof(char));
	if (!data)
		exit(0);
	while (42)
	{
		data_copy = data;
		line = get_next_line(fd);
		if (!line)
			break ;
		data = ft_strjoin(data, line);
		free(data_copy);
		if (!data)
			exit(1);
		free(line);
	}
	close(fd);
	map->data = ft_split(data, '\n');
	free(data);
}

void	initialize_map(t_game *game, t_render *render, t_map *map)
{
	initialize_data(map);
	if (!map->data)
		exit(1);
	initialize_size(map);
	initialize_collectibles(map);
	create_sprite(render, &map->tilemap, map->width * TILE_SIZE,
		(map->height + 1) * TILE_SIZE);
	if (!check_is_valid(map))
		exit_game(game);
}
