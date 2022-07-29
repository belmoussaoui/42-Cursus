/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacruz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:39:29 by pacruz            #+#    #+#             */
/*   Updated: 2021/11/21 18:43:35 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_row_left(char param, int tab[4][4], int row)
{
	int	j;
	int	n;
	int	pos;

	j = 1;
	n = 1;
	pos = 0;
	while (j < 4)
	{
		if (tab[row][pos] < tab[row][j])
		{
			n++;
			pos = j;
		}
		j++;
	}
	if (n == param - '0')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	is_row_right(char param, int tab[4][4], int row)
{
	int	j;
	int	n;
	int	pos;

	j = 3;
	n = 1;
	pos = 3;
	while (j >= 0)
	{
		if (tab[row][pos] < tab[row][j])
		{
			n++;
			pos = j;
		}
		j--;
	}
	if (n == param - '0')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	is_column_valid(char param, int tab[4][4], int col)
{
	int	j;
	int	n;
	int	pos;

	j = 1;
	n = 1;
	pos = 0;
	while (j < 4)
	{
		if (tab[pos][col] < tab[j][col])
		{
			n++;
			pos = j;
		}
		j++;
	}
	if (n == param - '0')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	is_column_down_valid(char param, int tab[4][4], int col)
{
	int	j;
	int	n;
	int	pos;

	j = 3;
	n = 1;
	pos = 3;
	while (j >= 0)
	{
		if (tab[pos][col] < tab[j][col])
		{
			n++;
			pos = j;
		}
		j--;
	}
	if (n == param - '0')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
