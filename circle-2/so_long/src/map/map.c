/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:40:48 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/12 14:58:56 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include <fcntl.h>

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
}
