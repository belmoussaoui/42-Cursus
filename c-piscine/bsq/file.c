/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 05:06:58 by bel-mous          #+#    #+#             */
/*   Updated: 2021/12/01 21:00:01 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int	get_line(int fd, char **line)
{
	char	c;
	char	*buffer;
	int		len;
	int		size_read;

	len = 0;
	buffer = malloc(sizeof(char) * 1);
	buffer[0] = '\0';
	size_read = 1;
	while (size_read > 0)
	{
		size_read = read(fd, &c, 1);
		if (size_read == -1)
			return (0);
		if (c == '\n')
			break ;
		if (add_char(line, &len, &buffer, &c) == 0)
		{
			free(buffer);
			return (0);
		}
	}
	free(buffer);
	return (1);
}

int	add_char(char **line, int *len, char **buffer, char *c)
{
	(*len)++;
	free(*line);
	*line = malloc(sizeof(char) * (*len + 2));
	if (*line == NULL)
		return (0);
	*line = ft_strcpy(*line, *buffer);
	ft_strncat(*line, c, 1);
	free(*buffer);
	*buffer = ft_strdup(*line);
	return (1);
}
