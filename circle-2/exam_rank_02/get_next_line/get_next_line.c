/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:44:21 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/19 19:12:58 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

char* ft_strjoin(char *s1, char *s2)
{
	int l = ft_strlen(s1) + ft_strlen(s2);
	char *res = malloc(sizeof(char) * (l + 1));
	int i = 0;
	int j = 0;

	res[l] = '\0';
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		j++;
		i++;
	}
	free(s1);
	return (res);
}

int	is_line(char *buf)
{
	while (*buf)
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

char *get_line(char *reader)
{
	int i = 0;
	while (reader[i] && reader[i] != '\n')
		i++;
	if (reader[i] == '\n')
		i++;
	char *line = malloc(sizeof(char) * (i + 1));
	int j = 0;
	while (j < i)
	{
		line[j] = reader[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

void set_buffer(char *reader, char* buffer)
{
	int i = 0;
	while (reader[i] && reader[i] != '\n')
		i++;
	if (reader[i] == '\n')
		i++;
	int j = 0;
	while (reader[i])
	{
		buffer[j] = reader[i];
		j++;
		i++;
	}
	buffer[j] = '\0';
}

#include <stdio.h>
char *get_next_line(int fd)
{
	int nbytes = BUFFER_SIZE;
	char buf[BUFFER_SIZE + 1];
	char *line;
	char *temp;
	static char buffer[BUFFER_SIZE + 1];
	
	buf[0] = '\0';
	temp = malloc(sizeof(char) * 1);
	temp[0] = '\0';
	temp = ft_strjoin(temp, buffer);
	while (!is_line(temp) && nbytes > 0)
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (nbytes < 0)
		{
			free(temp);
			return (NULL);
		}
		buf[nbytes] = '\0';
		temp = ft_strjoin(temp, buf);
	}
	if (nbytes == 0 && temp[0] == '\0')
	{
		free(temp);
		return (NULL);
	}
	line = get_line(temp);
	set_buffer(temp, buffer);
	free(temp);
	return (line);
}
