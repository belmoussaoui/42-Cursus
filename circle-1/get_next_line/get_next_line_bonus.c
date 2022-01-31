/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:24:01 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/31 11:55:07 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line_from(char *reader)
{
	char	*line;
	int		i;

	i = 0;
	while (reader[i] && reader[i] != '\n')
		i++;
	if (reader[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (reader[i] && reader[i] != '\n')
	{
		line[i] = reader[i];
		i++;
	}
	if (reader[i] == '\n')
	{
		line[i] = reader[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_buffer_from(char *reader)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	while (reader[i] && reader[i] != '\n')
		i++;
	if (reader[i] == '\n')
		i++;
	buffer = malloc(sizeof(char) * (ft_strlen(reader) - i + 1));
	if (buffer == NULL)
		return (NULL);
	j = 0;
	while (reader[i])
	{
		buffer[j] = reader[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	return (buffer);
}

static char	*read_line(int fd, char *reader)
{
	int		nbytes;
	char	*temp;
	char	buf[BUFFER_SIZE + 1];

	while (!ft_strchr(reader, '\n'))
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (nbytes < 0)
		{
			free(reader);
			return (NULL);
		}
		if (nbytes == 0)
			break ;
		buf[nbytes] = '\0';
		temp = ft_strjoin(reader, buf);
		free(reader);
		if (temp == NULL)
			return (NULL);
		reader = ft_strjoin("", temp);
		free(temp);
		if (reader == NULL)
			return (NULL);
	}
	return (reader);
}

static char	*init_line(char *buffer)
{
	char		*reader;

	if (buffer == NULL)
		reader = ft_strjoin("", "");
	else
	{
		reader = ft_strjoin("", buffer);
		free(buffer);
	}
	return (reader);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX] = {NULL};
	char		*line;
	char		*reader;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	reader = init_line(buffer[fd]);
	if (reader == NULL)
		return (NULL);
	reader = read_line(fd, reader);
	if (reader == NULL)
		return (NULL);
	if (reader[0] == '\0')
	{
		free(reader);
		return (NULL);
	}
	line = get_line_from(reader);
	buffer[fd] = get_buffer_from(reader);
	free(reader);
	if (buffer[fd] == NULL)
		return (NULL);
	return (line);
}
