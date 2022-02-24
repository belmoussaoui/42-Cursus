/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:30:43 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/24 19:10:51 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lock_sort(t_game *game)
{
	int i;
	t_action action;
	
	i = 0;
	while (i < game->n)
	{
		action = best_action(game);
		smart_rotate(action);
		command_pb();
	}
}

t_action	best_action(t_game *game)
{
	t_action	action;
	return (action);
}

void	smart_rotate(t_action action)
{
		
}