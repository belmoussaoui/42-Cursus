/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:30:43 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/25 22:11:50 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted_position(int nbr, t_game *game)
{
	int		i;
	int		pos;
	int		len;
	t_list	*elem;

	i = 0;
	elem = ft_lstget(game->stack_b, game->head);
	pos = 0;
	len = ft_lstlen(game->stack_b);
	while (elem && pos < len)
	{
		if (nbr > *((int *)elem->content))
			break ;
		elem = elem->next;
		if (elem == NULL)
			elem = game->stack_b;
		pos++;
	}
	return ((pos + game->head) % ft_lstlen(game->stack_b));
}

void double_rotate(t_game *game, t_action action)
{
	int i;
	
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

void double_reverse_rotate(t_game *game, t_action action)
{
	int i;
	int	len_a;
	int len_b;

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

void normal_rotate(t_game *game, t_action action)
{
	int i;
	int	len_a;
	int len_b;

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

void	smart_rotate(t_game *game, t_action action)
{
	int	len_a;
	int len_b;
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

int	get_score(t_action action, t_game *game)
{
	int	score;
	int	len_a;
	int len_b;

	len_a = ft_lstlen(game->stack_a);
	len_b = ft_lstlen(game->stack_b);
	if (action.index_a == -1 && action.index_a == -1)
		return (game->n);
	score = 0;
	if (action.index_a <= len_a - action.index_a)
		score += action.index_a;
	else
		score += len_a - action.index_a;
	if (action.index_b <= len_b - action.index_b)
		score += action.index_b;
	else
		score += len_b - action.index_b;
	return (score);
}

t_action	best_action(t_game *game)
{
	t_action	action;
	t_action	best;
	int			i;
	t_list		*elem;

	best.index_a = -1;
	best.index_b = -1;
	i = 0;
	elem = game->stack_a;
	while (elem)
	{
		action.index_a = i;
		action.index_b = sorted_position(*((int *) elem->content), game);
		if (get_score(action, game) <= get_score(best, game))
		{
			best.index_a = action.index_a;
			best.index_b = action.index_b;
		}
		elem = elem->next;
		i++;	
	}
	return (best);
}

void	lock_sort(t_game *game)
{
	int i;
	t_action action;
	
	i = 1;
	command_pb(game);
	while (i < game->n)
	{
		action = best_action(game);
		smart_rotate(game, action);
		command_pb(game);
		i++;
	}
	action.index_a = 0;
	action.index_b = game->head;
	smart_rotate(game, action);
	i = 0;
	while (i++ < game->n)
		command_pa(game);
}
