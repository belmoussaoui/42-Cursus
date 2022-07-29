/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:49:35 by lrondia           #+#    #+#             */
/*   Updated: 2021/11/21 18:43:02 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_solution_column(char *params, int tab[4][4])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < 8)
		{
			if (is_column_valid(params[i], tab, i / 2) == 0)
				return (0);
		}
		if (i >= 8 && i < 16)
		{
			if (is_column_down_valid(params[i], tab, i / 2 - 4) == 0)
				return (0);
		}
		i = i + 2;
	}
	return (1);
}

int	is_valid_solution_row(char *params, int tab[4][4])
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (i >= 16 && i < 23)
		{
			if (is_row_left(params[i], tab, i / 2 - 8) == 0)
				return (0);
		}
		if (i > 24)
		{
			if (is_row_right(params[i], tab, i / 2 - 12) == 0)
				return (0);
		}
		i = i + 2;
	}
	return (1);
}

int	is_valid_next(int tab[4][4], int col, int row)
{
	int	i;
	int	j;

	i = col;
	j = row;
	if (col == 0 && row == 0)
		return (1);
	while (i > 0)
	{
		i--;
		if (tab[row][i] == tab[row][col])
			return (0);
	}
	while (j > 0)
	{
		j--;
		if (tab[j][col] == tab[row][col])
			return (0);
	}
	return (1);
}

int	is_valid_arg(char *params)
{
	int	i;

	i = 0;
	while (params[i])
	{
		if (i % 2 == 0)
		{
			if (params[i] >= '1' && params[i] <= '4' )
				i++;
			else
				return (0);
		}
		else
		{
			if (params[i] == ' ')
				i++;
			else
				return (0);
		}
	}
	if (i != 31)
		return (0);
	return (1);
}
