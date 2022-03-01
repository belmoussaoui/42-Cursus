/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:45:32 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/01 18:36:43 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (*lst == NULL)
		return ;
	first = *lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
}

void	command_sa(t_game *game)
{
	write(1, "sa\n", 3);
	swap(&game->stack_a);
}

void	command_sb(t_game *game)
{
	write(1, "sb\n", 3);
	swap(&game->stack_b);
	if (game->head == 0)
		game->head = 1;
	if (game->head == 1)
		game->head = 0;
}

void	command_ss(t_game *game)
{
	write(1, "ss\n", 3);
	swap(&game->stack_a);
	swap(&game->stack_b);
	if (game->head == 0)
		game->head = 1;
	if (game->head == 1)
		game->head = 0;
}
