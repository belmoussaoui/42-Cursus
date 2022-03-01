/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:43:16 by bel-mous          #+#    #+#             */
/*   Updated: 2022/03/01 19:55:38 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_commands(t_list *commands)
{
	ft_lstclear(&commands, free);
}

int	is_sorted(t_list *stack_a, t_list *stack_b)
{
	int	value_a;
	int	value_b;

	if (ft_lstlen(stack_b) > 0)
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
	int		value;

	while (commands)
	{
		value = 0;
		command = (char *) commands->content;
		value += interpreter_push(game, command);
		value += interpreter_swap(game, command);
		value += interpreter_rotate(game, command);
		value += interpreter_reverse(game, command);
		commands = commands->next;
		if (value == 0)
		{
			free_commands(commands);
			exit_error(game);
		}
	}
	if (is_sorted(game->stack_a, game->stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

t_list	*read_commands(void)
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
	free_commands(commands);
	return (0);
}
