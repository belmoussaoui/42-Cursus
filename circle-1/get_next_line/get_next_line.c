/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:19:04 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/26 18:08:51 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_line(char *reader)
{
	char	*line;
	int		i;

	i = 0;
	while (reader[i] && reader[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
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

void	set_buffer(char *reader, char *buffer)
{
	int	i;
	int	j;

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

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*temp;
	char		*reader;
	char		*line;
	int			nbytes;

	if (fd < 0)
		return (NULL);
	reader = ft_strjoin("", buffer);
	if (reader == NULL)
		return (NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes < 0)
		{
			free(reader);
			return (NULL);
		}
		if (nbytes == 0)
			break ;
		buffer[nbytes] = '\0';
		temp = ft_strjoin(reader, buffer);
		if (temp == NULL)
		{
			free(reader);
			return (NULL);
		}
		free(reader);
		reader = ft_strjoin("", temp);
		free(temp);
		if (reader == NULL)
			return (NULL);
	}
	if (nbytes == 0 && reader[0] == '\0')
	{
		free(reader);
		return NULL;
	}
	line = get_line(reader);
	set_buffer(reader, buffer);
	free(reader);
	return (line);
}
