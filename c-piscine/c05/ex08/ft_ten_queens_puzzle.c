/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 23:44:48 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/24 01:34:38 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_display_solution(int board[10][10])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (board[j][i] == 1)
			{
				c = '0' + j;
				write(1, &c, 1);
			}	
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	ft_is_valid(int x, int y, int board[10][10])
{
	int	i;
	int	j;

	i = x;
	while (--i >= 0)
		if (board[y][i] == 1)
			return (0);
	j = y;
	while (--j >= 0)
		if (board[j][x] == 1)
			return (0);
	i = x;
	j = y;
	while (--i >= 0 && --j >= 0)
		if (board[j][i] == 1)
			return (0);
	i = x;
	j = y;
	while (++i < 10 && --j >= 0)
		if (board[j][i] == 1)
			return (0);
	return (1);
}

void	ft_check_solution(int board[10][10], int *count)
{
	int	i;
	int	j;
	int	count_queen;

	count_queen = 0;
	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			if (board[j][i] == 1)
				count_queen++;
			i++;
		}
		j++;
	}
	if (count_queen == 10)
	{
		ft_display_solution(board);
		(*count)++;
	}
}

void	ft_solve(int x, int y, int board[10][10], int *count)
{
	int	action;
	int	new_x;
	int	new_y;

	if (y == 10)
		ft_check_solution(board, count);
	else
	{
		new_x = x;
		new_y = y;
		if (++new_x == 10)
		{
			new_x = 0;
			new_y++;
		}
		action = 0;
		while (action <= 1)
		{
			board[y][x] = action;
			if (action == 0 || ft_is_valid(x, y, board))
				ft_solve(new_x, new_y, board, count);
			board[y][x] = 0;
			action++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10][10];
	int	res;

	res = 0;
	ft_solve(0, 0, board, &res);
	return (res);
}

// http://www.durangobill.com/N_Queens.html
// int	main(void)
// {
// 	ft_ten_queens_puzzle();
// 	return (0);
// }