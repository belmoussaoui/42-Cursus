/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:40:05 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/02 11:02:59 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **out, t_list **in)
{
	t_list	*elem;

	if (*out == NULL)
		return ;
	elem = *out;
	*out = elem->next;
	ft_lstadd_front(in, elem);
}

void	command_pa(t_game *game)
{
	write(1, "pa\n", 3);
	push(&game->stack_b, &game->stack_a);
}

void	command_pb(t_game *game)
{
	int	a;
	int	b;

	write(1, "pb\n", 3);
	push(&game->stack_a, &game->stack_b);
	game->head++;
	a = *((int *) game->stack_b->content);
	b = *((int *) ft_lstget(game->stack_b, game->head)->content);
	if (a > b)
		game->head = 0;
}
