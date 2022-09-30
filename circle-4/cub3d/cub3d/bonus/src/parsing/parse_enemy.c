/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:46:48 by jboumal           #+#    #+#             */
/*   Updated: 2022/09/29 12:46:51 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_enemy(t_game *game, int fd)
{
	char	*line;
	char	**line_split;
	double	x;
	double	y;

	line = get_next_non_empty_line(fd);
	while (line)
	{
		line_split = ft_split(line, ' ');
		if (line[0] == 'R')
			game->reflect = !str_n_cmp(line_split[1], "ON", 2);
		else
		{
			x = ft_atoi(line_split[1]) + 0.5;
			y = ft_atoi(line_split[2]) + 0.5;
			create_enemy(game, x, y, line_split[0]);
		}
		free(line);
		str_arr_free(line_split);
		line = get_next_non_empty_line(fd);
	}
}
