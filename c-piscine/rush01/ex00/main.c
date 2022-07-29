/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:07:28 by lrondia           #+#    #+#             */
/*   Updated: 2021/11/21 19:23:29 by pacruz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "library_rush.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	print_matriz(int matriz[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar('0' + matriz[i][j]);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
	return (1);
}

int	recursive(int col, int row, int tab[4][4], char *params)
{
	int	next_row;
	int	next_col;
	int	i;

	if (col == 4 && row == 0)
	{
		if (is_valid_solution_column(params, tab)
			&& is_valid_solution_row(params, tab))
			return (1);
	}
	else
	{
		i = 0;
		next_position(&next_row, &next_col, row, col);
		while (++i <= 4)
		{
			tab[row][col] = i;
			if (is_valid_next(tab, col, row)
				&& recursive(next_col, next_row, tab, params))
				return (1);
		}
	}
	return (0);
}

void	next_position(int *next_row, int *next_col, int row, int col)
{
	*next_row = row;
	*next_col = col;
	if (*next_row == 3)
	{
		*next_row = 0;
		(*next_col)++;
	}
	else
		(*next_row)++;
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	tab[4][4];
	int	res;

	i = 0;
	j = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!is_valid_arg(argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	res = recursive(j, i, tab, argv[1]);
	if (res == 0)
		write(1, "Error\n", 6);
	else
		print_matriz(tab);
	return (0);
}
