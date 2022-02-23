/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:04:29 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/23 13:20:00 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack(t_game *game, int data[])
{
	int	i;

	i = 0;
	game->stack_a = NULL;
	game->stack_b = NULL;
	while (i < game->n)
	{
		ft_lstadd_back(&game->stack_a, ft_lstnew(data + i));
		i++;
	}
	game->head = NULL;
}

t_game	setup(int data[])
{
	t_game	game;
	game.n = 100;
	initialize_stack(&game, data);
	return (game);
}