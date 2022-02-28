/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:52:15 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/26 11:46:37 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_list **lst)
{
	int		len;
	t_list	*before;
	t_list	*last;

	len = ft_lstlen(*lst);
	before = ft_lstget(*lst, len - 2);
	last = before->next;
	before->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	command_rra(t_game *game)
{
	write(1, "rra\n", 4);
	reverse_rotate(&game->stack_a);
}

void	command_rrb(t_game *game)
{
	write(1, "rrb\n", 4);
	reverse_rotate(&game->stack_b);
	game->head += 1;
	game->head %= ft_lstlen(game->stack_b);
}

void	command_rrr(t_game *game)
{
	write(1, "rrr\n", 4);
	reverse_rotate(&game->stack_a);
	reverse_rotate(&game->stack_b);
	game->head += 1;
	game->head %= ft_lstlen(game->stack_b);
}
