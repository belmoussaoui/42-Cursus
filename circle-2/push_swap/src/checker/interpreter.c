/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:12:34 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/01 19:55:00 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	interpreter_push(t_game *game, char *command)
{
	int	len;

	len = ft_strlen(command);
	if (!ft_strncmp(command, "pa\n", len))
		push(&game->stack_b, &game->stack_a);
	else if (!ft_strncmp(command, "pb\n", len))
		push(&game->stack_a, &game->stack_b);
	else
		return (0);
	return (1);
}

int	interpreter_swap(t_game *game, char *command)
{
	int	len;

	len = ft_strlen(command);
	if (!ft_strncmp(command, "sa\n", len))
		swap(&game->stack_a);
	else if (!ft_strncmp(command, "sb\n", len))
		swap(&game->stack_b);
	else if (!ft_strncmp(command, "ss\n", len))
	{
		swap(&game->stack_a);
		swap(&game->stack_b);
	}
	else
		return (0);
	return (1);
}

int	interpreter_rotate(t_game *game, char *command)
{
	int	len;

	len = ft_strlen(command);
	if (!ft_strncmp(command, "ra\n", len))
		rotate(&game->stack_a);
	else if (!ft_strncmp(command, "rb\n", len))
		rotate(&game->stack_b);
	else if (!ft_strncmp(command, "rr\n", len))
	{
		rotate(&game->stack_a);
		rotate(&game->stack_b);
	}
	else
		return (0);
	return (1);
}

int	interpreter_reverse(t_game *game, char *command)
{
	int	len;

	len = ft_strlen(command);
	if (!ft_strncmp(command, "rra\n", len))
		reverse_rotate(&game->stack_a);
	else if (!ft_strncmp(command, "rrb\n", len))
		reverse_rotate(&game->stack_b);
	else if (!ft_strncmp(command, "rrr\n", len))
	{
		reverse_rotate(&game->stack_a);
		reverse_rotate(&game->stack_b);
	}
	else
		return (0);
	return (1);
}
