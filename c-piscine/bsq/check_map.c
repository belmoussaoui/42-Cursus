/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:46:36 by bel-mous          #+#    #+#             */
/*   Updated: 2021/12/01 21:30:44 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

int	check_map(char *line, t_data *data, int count_line)
{
	int	is_valid;

	if (count_line == 0)
	{
		data->columns = ft_strlen(line);
		data->data = malloc(sizeof(int) * data->columns * data->lines);
	}
	if (count_line >= data->lines)
		return (0);
	is_valid = set_map(line, data, count_line);
	return (is_valid);
}

int	set_map(char *line, t_data *data, int count_line)
{
	int		i;
	char	s;

	i = 0;
	while (line[i])
	{
		s = line[i];
		if (s == data->symbols[0])
			data->data[i + count_line * data->columns] = 0;
		else if (s == data->symbols[1])
			data->data[i + count_line * data->columns] = 1;
		else
			return (0);
		i++;
	}
	if (i != data->columns)
		return (0);
	return (1);
}
