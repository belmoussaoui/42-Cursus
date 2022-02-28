/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:49:11 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/26 12:26:50 by bel-mous         ###   ########.fr       */
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

int	get_double_rotate_score(int index_a, int index_b)
{
	int	score;

	score = 0;
	if (index_a < index_b)
		score += index_b;
	else
		score += index_a;
	return (score);
}

int	get_score(t_action action, t_game *game)
{
	int	score;
	int	len_a;
	int	len_b;

	len_a = ft_lstlen(game->stack_a) - action.index_a;
	len_b = ft_lstlen(game->stack_b) - action.index_b;
	if (action.index_a == -1 && action.index_a == -1)
		return (game->n);
	score = 0;
	if (action.index_a <= len_a && action.index_b <= len_b)
		return (get_double_rotate_score(action.index_a, action.index_b));
	else if (action.index_a > len_a && action.index_b > len_b)
		return (get_double_rotate_score(len_a, len_b));
	else
	{
		if (action.index_a <= len_a)
			score += action.index_a;
		else
			score += len_a;
		if (action.index_b <= len_b)
			score += action.index_b;
		else
			score += len_b;
	}
	return (score);
}

t_action	lock_action(t_game *game)
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
		if (get_score(action, game) < get_score(best, game))
		{
			best.index_a = action.index_a;
			best.index_b = action.index_b;
		}
		elem = elem->next;
		i++;
	}
	return (best);
}
