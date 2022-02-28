/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:48:00 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/26 12:01:28 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	double_rotate(t_game *game, t_action action)
{
	int	i;

	i = 0;
	while (i < action.index_a && i < action.index_b)
	{
		command_rr(game);
		i++;
	}
	while (i < action.index_a)
	{
		command_ra(game);
		i++;
	}
	while (i < action.index_b)
	{
		command_rb(game);
		i++;
	}
}

void	double_reverse_rotate(t_game *game, t_action action)
{
	int	i;
	int	len_a;
	int	len_b;

	len_a = ft_lstlen(game->stack_a);
	len_b = ft_lstlen(game->stack_b);
	i = 0;
	while (i < len_a - action.index_a && i < len_b - action.index_b)
	{
		command_rrr(game);
		i++;
	}
	while (i < len_a - action.index_a)
	{
		command_rra(game);
		i++;
	}
	while (i < len_b - action.index_b)
	{
		command_rrb(game);
		i++;
	}
}

void	normal_rotate(t_game *game, t_action action)
{
	int	i;
	int	len_a;
	int	len_b;

	len_a = ft_lstlen(game->stack_a);
	len_b = ft_lstlen(game->stack_b);
	i = 0;
	if (action.index_a <= len_a - action.index_a)
		while (i++ < action.index_a)
			command_ra(game);
	else
		while (i++ < len_a - action.index_a)
			command_rra(game);
	i = 0;
	if (action.index_b <= len_b - action.index_b)
		while (i++ < action.index_b)
			command_rb(game);
	else
		while (i++ < len_b - action.index_b)
			command_rrb(game);
}

void	lock_rotate(t_game *game, t_action action)
{
	int	len_a;
	int	len_b;
	int	index_a;
	int	index_b;

	len_a = ft_lstlen(game->stack_a);
	len_b = ft_lstlen(game->stack_b);
	index_a = action.index_a;
	index_b = action.index_b;
	if (index_a <= len_a - index_a && index_b <= len_b - index_b)
		double_rotate(game, action);
	else if (len_a - index_a < index_a && len_b - index_b < index_b)
		double_reverse_rotate(game, action);
	else
		normal_rotate(game, action);
}
