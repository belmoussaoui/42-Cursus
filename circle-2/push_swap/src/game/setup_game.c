/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:04:29 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/26 21:56:02 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_game(t_game *game)
{
	if (game->numbers)
		free(game->numbers);
	if (game->stack_a)
		ft_lstclear(&game->stack_a, NULL);
	if (game->stack_b)
		ft_lstclear(&game->stack_b, NULL);
}

void	exit_error(t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	free_game(game);
	exit(1);
}

void	initialize_stacks(t_game *game)
{
	int		i;
	t_list	*new;

	i = 0;
	while (i < game->n)
	{
		new = ft_lstnew(game->numbers + i);
		if (!new)
		{
			free_game(game);
			exit(1);
		}
		ft_lstadd_back(&game->stack_a, new);
		i++;
	}
	game->head = -1;
}

void	initialize_numbers(t_game *game, int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
		argv = handle_one_arg(argv[0]);
	else
		argv = handle_many_args(argc - 1, argv);
	while (argv[game->n])
		game->n++;
	game->numbers = malloc(sizeof(int) * game->n);
	if (!game->numbers)
	{
		free(argv);
		exit(1);
	}
	while (i < game->n)
	{
		game->numbers[i] = check_number(argv[i], game, argv);
		i++;
	}
	check_duplicates(game, argv);
	free_argv(game, argv, 0);
}

t_game	setup_game(int argc, char **argv)
{
	t_game	game;

	game.stack_a = NULL;
	game.stack_b = NULL;
	game.n = 0;
	initialize_numbers(&game, argc, argv + 1);
	initialize_stacks(&game);
	return (game);
}
