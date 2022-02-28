/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:30:43 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/26 12:29:50 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lock_end(t_game *game)
{
	int			i;
	t_action	action;

	action.index_a = 0;
	action.index_b = game->head;
	lock_rotate(game, action);
	i = 0;
	while (i++ < game->n)
		command_pa(game);
}

void	lock_sort(t_game *game)
{
	int			i;
	t_action	action;

	i = 1;
	command_pb(game);
	while (i < game->n)
	{
		action = lock_action(game);
		lock_rotate(game, action);
		command_pb(game);
		i++;
	}
	lock_end(game);
}
