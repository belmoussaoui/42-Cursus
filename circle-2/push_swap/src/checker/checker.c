/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:43:16 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/28 21:23:02 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../push_swap.h"

// void	run()
// {
	
// }

char*	read_instructions(char *c)
{
	
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_list	*commands;
	//char	*commands;
	game = setup_game(argc, argv);
	while (get_next_line(0))
		;
	//commands = read_commands();
	//run(&game);
	printf("ok\n");
	free_game(&game);
	return (0);
}
