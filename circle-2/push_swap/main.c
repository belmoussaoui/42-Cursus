/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:03:34 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/20 16:35:22 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void insert(t_list **stack, int start, int end)
{
	int i = 0;
	int j = 0;
	int c = 0;
	(void) end;

	while (i < start)
	{
		rotate(stack);
		c++;
		i++;
	}
	while (j < start - end)
	{
		reverse_rotate(stack);
		swap(stack);
		c += 2;
		j++;
	}
	j = 0;
	while (j < end)
	{
		c += 1;
		reverse_rotate(stack);
		j++;
	}
	printf("%d\n", c);
}

int main()
{
	t_game game;
	int	data[5] = {1, 5, 2, 4, 3};
	
	game = setup(data);
	print_game(game);
	printf("insert:\n");
	insert(&game.stack_a, 4, 0);
	print_game(game);
	return (0);
}