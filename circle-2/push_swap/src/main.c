/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:03:34 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/02 10:54:34 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	int	value_a;
	int	value_b;

	while (stack->next)
	{
		value_a = *((int *) stack->content);
		stack = stack->next;
		value_b = *((int *) stack->content);
		if (value_b < value_a)
			return (0);
	}
	return (1);
}

void	play(t_game *game)
{
	if (game->n == 0 || is_sorted(game->stack_a))
		return ;
	if (game->n <= 5)
		twin_sort(game);
	else
		lock_sort(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = setup_game(argc, argv);
	play(&game);
	free_game(&game);
	return (0);
}
