/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:09:17 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/05 10:45:01 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_border(int i, int j, t_map	map)
{
	return (!i || !j || i == map.height - 1 || j == map.width - 1);
}

static bool	check_cell(int i, int j, t_map map)
{
	if (is_border(i, j, map) && !map.data[i * map.width + j])
		return (true);
	return (!is_border(i, j, map) && !map.data[i * map.width + j]
		&& (map.data[(i - 1) * map.width + j] == -1
			|| map.data[(i + 1) * map.width + j] == -1
			|| map.data[i * map.width + j - 1] == -1
			|| map.data[i * map.width + j + 1] == -1));
}

void	check_map(t_game *g)
{
	int		i;
	int		j;
	t_map	map;

	map = g->map;
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (check_cell(i, j, map))
				exit_error("invalid map formating");
			j++;
		}
		i++;
	}
}
