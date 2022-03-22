/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:18:16 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/22 15:50:42 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	is_rectangular(t_map *map)
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

int	is_closed_by_wall(t_map *map)
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

int	is_contain_components(t_map *map)
{
	int		x;
	int		y;
	char	c;

	if (map->players <= 0 || map->collectibles <= 0 || map->exits <= 0)
		return (0);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->data[y][x];
			if (!(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == 'M'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	is_ber_extension(t_map *map)
{
	char	*dot;
	int		len;

	dot = ft_strrchr(map->name, '.');
	if (!dot)
		return (0);
	len = ft_strlen(dot);
	if (ft_strncmp(".ber", dot, len) || len != 4)
		return (0);
	return (1);
}

int	check_is_valid(t_map *map)
{
	if (map->height == 0)
		return (error_message("file is invalid\n"));
	if (!is_ber_extension(map))
		return (error_message("wrong file extension\n"));
	if (!is_contain_components(map))
		return (error_message("map content is invalid\n"));
	if (!is_rectangular(map))
		return (error_message("map is not rectangular\n"));
	if (!is_closed_by_wall(map))
		return (error_message("map is not closed\n"));
	return (1);
}
