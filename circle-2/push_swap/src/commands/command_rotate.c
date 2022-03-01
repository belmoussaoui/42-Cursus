/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:43:26 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/01 13:13:05 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	if (lst == NULL)
		return ;
	first = *lst;
	last = ft_lstlast(first);
	last->next = *lst;
	*lst = first->next;
	first->next = NULL;
}

void	command_ra(t_game *game)
{
	write(1, "ra\n", 3);
	rotate(&game->stack_a);
}

void	command_rb(t_game *game)
{
	write(1, "rb\n", 3);
	rotate(&game->stack_b);
	game->head -= 1;
	if (game->head < 0)
		game->head = ft_lstlen(game->stack_b) - 1;
}

void	command_rr(t_game *game)
{
	write(1, "rr\n", 3);
	rotate(&game->stack_a);
	rotate(&game->stack_b);
	game->head -= 1;
	if (game->head < 0)
		game->head = ft_lstlen(game->stack_b) - 1;
}
