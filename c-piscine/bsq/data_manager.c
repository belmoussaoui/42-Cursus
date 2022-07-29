/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:21:58 by bel-mous          #+#    #+#             */
/*   Updated: 2021/12/01 18:58:24 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_manager.h"
#include "check_header.h"
#include "check_map.h"

t_data	load_file(char *file)
{
	t_data	data;
	int		fd;

	data.state = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (data);
	if (read_map(fd, &data) == 0)
		return (data);
	data.state = 1;
	return (data);
}

int	read_map(int fd, t_data *data)
{
	char	*line;
	int		count_line;

	line = malloc(sizeof(char) * 1);
	line[0] = '\0';
	if (get_line(fd, &line) == 0)
		return (0);
	if (check_header(line, data) == 0)
		return (0);
	count_line = 0;
	while (get_line(fd, &line) && line[0])
	{
		if (check_map(line, data, count_line) == 0)
		{
			free(line);
			free(data->data);
			return (0);
		}
		line[0] = '\0';
		count_line++;
	}
	free(line);
	if (count_line != data->lines)
		return (0);
	return (1);
}

t_data	load_input(void)
{
	t_data	data;
	char	*line;

	data.state = 0;
	line = malloc(sizeof(char) * 1);
	line[0] = '\0';
	get_line(0, &line);
	if (check_header(line, &data) == 0)
		return (data);
	if (read_input(line, &data) == 0)
		return (data);
	data.state = 1;
	return (data);
}

int	read_input(char *line, t_data *data)
{
	int		count_line;

	count_line = 0;
	while (get_line(0, &line))
	{
		if (check_map(line, data, count_line) == 0)
		{
			free(line);
			free(data->data);
			return (0);
		}
		line[0] = '\0';
		count_line++;
		if (count_line >= data->lines)
			break ;
	}
	free(line);
	return (1);
}
