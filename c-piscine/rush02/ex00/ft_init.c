/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:29:36 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/28 14:16:41 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_check_line(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] >= 33 && line[i] <= 126)
			return (1);
		i++;
	}
	return (0);
}

void	ft_increment_dict_size(t_data *data, char *save)
{
	int	i;

	i = 0;
	while (data->file_str[i])
	{
		if (ft_check_line(data, &data->file_str[i]) == 1)
		{
			data->dict_size++;
		}
		while (data->file_str[i] && data->file_str[i] != '\n')
			i++;
		if (data->file_str[i] == '\n')
			i++;
	}
}

int	ft_dict_size(t_data *data)
{
	char	tmp[2];
	int		lu;

	data->file_str = (char *)malloc(sizeof(char) * 2);
	if (!data->file_str)
		return (0);
	lu = read(data->fd, data->file_str, 1);
	if (lu == 0)
		return (0);
	while (lu > 0)
	{
		lu = read(data->fd, tmp, 1);
		data->file_str = ft_join(data->file_str, tmp);
	}
	ft_increment_dict_size(data, data->file_str);
	return (1);
}

int	ft_init(t_data *data, char **argv)
{
	
	data->matrice_key = 0;
	data->number_size = 0;
	data->dict_size = 0;
	data->number = NULL;
	data->dict = NULL;
	data->file_str = NULL;
	if (argv[2])
	{
		data->dict_path = *argv[1];
		data->fd = ft_open_file(argv[1]);
		if (ft_dict_size(data) == 0)
			return (0);
		if (ft_rules_lines(data) == 0)
			return (0);
	}
	else
	{
		
	}
	return (1);
}