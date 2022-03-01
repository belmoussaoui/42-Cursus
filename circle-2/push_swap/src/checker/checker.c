/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:43:16 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/01 13:19:36 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../push_swap.h"

void	run(t_game *game, t_list *commands)
{
	char	*command;
	int		len;

	while (commands)
	{
		command = (char *) commands->content;
		len = ft_strlen(command);
		if (!ft_strncmp(command, "pa\n", len))
			push(&game->stack_b, &game->stack_a);
		else if (!ft_strncmp(command, "pb\n", len))
			push(&game->stack_a, &game->stack_b);
		else if (!ft_strncmp(command, "sa\n", len))
			swap(&game->stack_a);
		else if (!ft_strncmp(command, "sb\n", len))
			swap(&game->stack_b);
		else if (!ft_strncmp(command, "ss\n", len))
		{
			swap(&game->stack_a);
			swap(&game->stack_b);
		}
		else if (!ft_strncmp(command, "ra\n", len))
			swap(&game->stack_a);
		else if (!ft_strncmp(command, "rb\n", len))
			swap(&game->stack_b);
		else if (!ft_strncmp(command, "rr\n", len))
		{
			swap(&game->stack_a);
			swap(&game->stack_b);
		}
		else if (!ft_strncmp(command, "rra\n", len))
			swap(&game->stack_a);
		else if (!ft_strncmp(command, "rrb\n", len))
			swap(&game->stack_b);
		else if (!ft_strncmp(command, "rrr\n", len))
		{
			swap(&game->stack_a);
			swap(&game->stack_b);
		}
		commands = commands->next;
	}
}

t_list	*read_commands()
{
	t_list	*commands;
	char	*line;

	commands = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ft_lstadd_back(&commands, ft_lstnew(line));
	}
	return (commands);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_list	*commands;
	
	game = setup_game(argc, argv);
	commands = read_commands();
	run(&game, commands);
	free_game(&game);
	// free_commands();
	return (0);
}
