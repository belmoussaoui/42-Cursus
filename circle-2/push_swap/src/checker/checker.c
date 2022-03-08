/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:43:16 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/02 11:14:27 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_command(char *command)
{
	char	*commands[11];
	int		i;
	int		len;

	commands[0] = "pa\n";
	commands[1] = "pb\n";
	commands[2] = "sa\n";
	commands[3] = "sb\n";
	commands[4] = "ss\n";
	commands[5] = "ra\n";
	commands[6] = "rb\n";
	commands[7] = "rr\n";
	commands[8] = "rra\n";
	commands[9] = "rrb\n";
	commands[10] = "rrr\n";
	i = 0;
	len = ft_strlen(command);
	while (i < 11)
	{
		if (!ft_strncmp(command, commands[i], len))
			return (1);
		i++;
	}
	return (0);
}

int	is_sorted(t_list *stack_a, t_list *stack_b)
{
	int	value_a;
	int	value_b;

	if (stack_a == NULL)
		return (0);
	if (stack_b != NULL)
		return (0);
	while (stack_a->next)
	{
		value_a = *((int *) stack_a->content);
		stack_a = stack_a->next;
		value_b = *((int *) stack_a->content);
		if (value_b < value_a)
			return (0);
	}
	return (1);
}

void	run(t_game *game, t_list *commands)
{
	char	*command;

	while (commands)
	{
		command = (char *) commands->content;
		interpreter_push(game, command);
		interpreter_swap(game, command);
		interpreter_rotate(game, command);
		interpreter_reverse(game, command);
		commands = commands->next;
	}
	if (is_sorted(game->stack_a, game->stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

t_list	*read_commands(t_game *game)
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
		if (!is_command(line))
		{
			ft_lstclear(&commands, free);
			exit_error(game);
		}
	}
	return (commands);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_list	*commands;

	game = setup_game(argc, argv);
	if (game.n > 0)
	{
		commands = read_commands(&game);
		run(&game, commands);
		ft_lstclear(&commands, free);
	}
	free_game(&game);
	return (0);
}
