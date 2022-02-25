/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:04:29 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/25 21:59:17 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_error()
{
	write(2 , "Error\n", 6);
	exit(1);
}

int	check_number(char *nbr)
{
	int		i;
	long	res;
	int 	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (nbr[i] == '+')
		i++;
	if (nbr[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			exit_error();
		res = res * 10 + nbr[i] - '0'; 
		i++;
		if (res > INT_MAX && !(res == (long)INT_MAX + 1 && sign == -1))
			exit_error();
	}
	return (res * sign);
}

void	check_duplicates(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->n)
	{
		j = i + 1;
		while (j < game->n)
		{
			if (game->numbers[i] == game->numbers[j])
				exit_error();
			j++;
		}
		i++;
	}
}

void	initialize_numbers(t_game *game, int argc, char **argv)
{
	int	i;

	i = 0;
	game->n = argc - 1;
	game->numbers = malloc(sizeof(int) * game->n);
	if (!game->numbers)
		exit(1);
	while (i < game->n)
	{
		game->numbers[i] = check_number(argv[i]);
		i++;
	}
	check_duplicates(game);
}

void	initialize_stacks(t_game *game)
{
	int		i;
	t_list	*new;

	i = 0;
	game->stack_a = NULL;
	game->stack_b = NULL;
	while (i < game->n)
	{
		new = ft_lstnew(game->numbers + i);
		if (!new)
			exit(1);
		ft_lstadd_back(&game->stack_a, new);
		i++;
	}
	game->head = -1;
}

t_game	setup_game(int argc, char **argv)
{
	t_game	game;
	
	game.n = 5;
	if (argc < 2)
		exit_error();
	initialize_numbers(&game, argc, argv + 1);
	initialize_stacks(&game);
	return (game);
}