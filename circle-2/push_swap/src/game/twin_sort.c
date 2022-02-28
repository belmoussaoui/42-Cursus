/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twin_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:40:28 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/28 17:06:58 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two_sort(t_game *game)
{
	int		a;
	int		b;
	t_list	*stack;

	stack = NULL;
	if (ft_lstlen(game->stack_a) == 2)
		stack = game->stack_a;
	if (ft_lstlen(game->stack_b) == 2)
		stack = game->stack_b;
	if (stack == NULL)
		return ;
	a = *((int *) stack->content);
	b = *((int *) stack->next->content);
	if (a > b && stack == game->stack_a)
		command_sa(game);
	if (a > b && stack == game->stack_b)
		command_sb(game);
}

void	three_sort(t_game *game)
{
	int	a;
	int	b;
	int	c;

	if (ft_lstlen(game->stack_a) != 3)
		return ;
	a = *((int *) ft_lstget(game->stack_a, 0)->content);
	b = *((int *) ft_lstget(game->stack_a, 1)->content);
	c = *((int *) ft_lstget(game->stack_a, 2)->content);
	if (a < c && b > c)
	{
		command_rra(game);
		command_sa(game);
	}
	else if (a > b && a < c)
		command_sa(game);
	else if (a < b && c < a)
		command_rra(game);
	else if (a > b && b > c)
	{
		command_sa(game);
		command_rra(game);
	}
	else if (a > b && b < c)
		command_ra(game);
}

void	twin_merge(t_game *game)
{
	int	i;
	int	j;
	int	a;

	i = ft_lstlen(game->stack_b);
	if (game->n <= 3)
		return ;
	j = 0;
	while (i > 0)
	{
		a = *((int *) game->stack_b->content);
		while (a > *((int *) ft_lstget(game->stack_a, 0)->content))
		{
			command_ra(game);
			j++;
			if (j >= ft_lstlen(game->stack_a))
				break ;
		}
		command_pa(game);
		i--;
	}
}
#include <stdio.h>
void	twin_end(t_game *game)
{
	int		min;
	t_list	*stack;
	int 	i;
	int		len;

	min = 0;
	i = 1;
	stack = game->stack_a;
	len = ft_lstlen(stack);
	while (i < len)
	{
		if (*((int *) ft_lstget(stack, i)->content)
			< *((int *) ft_lstget(stack, min)->content))
			min = i;
		i++;
	}
	i = 0;
	if (min <= len - min)
		while (i++ < min)
			command_ra(game);
	else
		while (i++ < len - min)
			command_rra(game);
}

void	twin_sort(t_game *game)
{
	int	i;

	i = 0;
	while (ft_lstlen(game->stack_a) > 3)
		command_pb(game);
	two_sort(game);
	three_sort(game);
	twin_merge(game);
	twin_end(game);
}
