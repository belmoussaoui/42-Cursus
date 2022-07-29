/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:47:15 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/30 21:17:53 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_header.h"

int	check_header(char *line, t_data *data)
{
	int	i;

	i = 0;
	if (set_count_line(line, data, &i) == 0)
		return (0);
	if (set_symbols(line, data, &i) == 0)
		return (0);
	return (1);
}

int	set_count_line(char *line, t_data *data, int *i)
{
	int	res;

	res = 0;
	while (line[*i] && line[*i] >= '0' && line[*i] <= '9'
		&& *i < ft_strlen(line) - 3)
	{
		res = res * 10 + line[*i] - '0';
		(*i)++;
	}
	data->lines = res;
	if (data->lines == 0)
		return (0);
	return (1);
}

int	set_symbols(char *line, t_data *data, int *i)
{
	int		j;
	char	s[3];

	j = 0;
	if (ft_strlen(line) != *i + 3)
		return (0);
	while (line[*i] != '\0')
	{
		data->symbols[j] = line[*i];
		(*i)++;
		j++;
	}
	s[0] = data->symbols[0];
	s[1] = data->symbols[1];
	s[2] = data->symbols[2];
	if (s[0] == s[1] || s[1] == s[2] || s[2] == s[0])
		return (0);
	return (1);
}
