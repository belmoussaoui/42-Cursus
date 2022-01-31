/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:24:01 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/30 22:06:46 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static void	get_buffer_from(char *reader, char *buffer)
{
	int		i;
	int		j;

	i = 0;
	while (reader[i] && reader[i] != '\n')
		i++;
	if (reader[i] == '\n')
		i++;
	j = 0;
	while (reader[i])
	{
		buffer[j] = reader[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
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

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE] = {'\0'};
	char		*line;
	char		*reader;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reader = ft_strjoin("", buffer);
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
	get_buffer_from(reader, buffer);
	free(reader);
	return (line);
}
