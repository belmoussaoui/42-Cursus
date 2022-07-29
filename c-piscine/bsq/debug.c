/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:18:04 by lrondia           #+#    #+#             */
/*   Updated: 2021/12/01 07:32:23 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_data(t_data data)
{
	int	i;

	i = 0;
	printf("%d\n", data.lines);
	printf("%d\n", data.columns);
	printf("%c, %c, %c\n", data.symbols[0], data.symbols[1], data.symbols[2]);
	while (i < (data.lines * data.columns))
	{
		printf("%d", data.data[i]);
		i++;
		if (i % data.columns == 0)
			printf("\n");
	}
}

void	print_tab(int *tab, int lines, int columns)
{
	int	i;

	i = 0;
	while (i < (lines * columns))
	{
		printf("%d ", tab[i]);
		i++;
		if (i % columns == 0)
			printf("\n");
	}
}

void	initialize_map(t_data *data)
{
	int	i;

	i = 0;
	data->lines = 3;
	data->columns = 6;
	data->symbols[0] = '.';
	data->symbols[1] = 'o';
	data->symbols[2] = 'x';
	data->data = malloc(sizeof(int) * data->lines * data->columns);
	while (i < (data->lines * data->columns))
	{
		data->data[i] = 0;
		i++;
	}
	data->data[1] = 1;
	data->data[2] = 1;
	data->data[14] = 1;
	data->data[17] = 1;
	data->state = 1;
}
