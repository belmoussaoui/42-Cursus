/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:24:16 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/20 15:41:18 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_game(t_game game)
{
	t_list *stack_a;
	t_list *stack_b;
	
	stack_a = game.stack_a;
	stack_b = game.stack_b;
	printf("stack a : ");
	while (stack_a)
	{
		printf("%d ", *((int *) stack_a->content));
		stack_a = stack_a->next;
	}
	printf("\n");
	printf("stack b : ");
	while (stack_b)
	{
		printf("%d ", *((int *) stack_b->content));
		stack_b = stack_b->next;
	}
	printf("\n");
}

void	test_instructions(t_game game)
{
	printf("- push b:\n");
	push(&game.stack_a, &game.stack_b);
	print_game(game);
	printf("- swap a:\n");
	swap(&game.stack_a);
	print_game(game);
	printf("- rotate a:\n");
	rotate(&game.stack_a);
	print_game(game);
	printf("- reverse rotate a:\n");
	reverse_rotate(&game.stack_a);
	print_game(game);
}