/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_non_empty_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:53:07 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/04 22:13:50 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_empty_line(char *line)
{
	if (!line)
		return (0);
	while (*line == ' ')
		line++;
	return (*line == '\n' || *line == '\r');
}

char	*get_next_non_empty_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line && is_empty_line(line))
	{
		free(line);
		return (get_next_non_empty_line(fd));
	}
	return (line);
}
