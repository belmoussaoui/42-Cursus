/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:57:35 by llaruell          #+#    #+#             */
/*   Updated: 2021/11/28 14:28:08 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_char_is_printable(char c)
{
	if (c <= 31 || c >= 127)
			return (0);
	return (1);
}


int ft_is_numeric(char *number)
{
	int i;

	i = 0;
	if (!number)
		return (0);
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int ft_strcmp(char *number, char *u_i_max)
{
	int i;

	i = 0;
	while (number[i] && u_i_max[i] && number[i] == u_i_max[i])
		i++;
	return (number[i] - u_i_max[i]);
}

int ft_open_file(char *dict)
{
	int fd;

	fd = open(dict, O_DIRECTORY);
	if (fd != -1)
		return (0);
	fd = open(dict, O_RDONLY);
	if (fd == -1)
		return (0);
	return (fd);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}