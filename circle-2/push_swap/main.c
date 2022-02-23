/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:03:34 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/23 13:19:35 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


int insert(t_game *game, int pos)
{
	int c = 0;
	int len = 0;
	int i = 0;
	t_list *elem;

	elem = game->stack_b;
	while (elem)
	{
		len++;
		elem = elem->next;
	}

	pos = pos % len;

		
	if (len - pos < pos)
	{
		
		while (i < len - pos)
		{
			game->head_index += 1;
			if (game->head_index >= len)
			{
				game->head_index = 0;
			}
			printf("rr\n");
			c++;
			reverse_rotate(&game->stack_b);
			i++;
		}
		c++;
		printf("pa\n");
		push(&game->stack_a, &game->stack_b);
		if (*((int *) game->head->content) > *((int *) game->stack_b->content))
			game->head_index += 1;
		i = 0;
	}
	else
	{	

		while (i < pos)
		{
			game->head_index -= 1;
			if (game->head_index < 0)
			{
				game->head_index = len - 1;
			}
			c++;
			printf("r\n");
			rotate(&game->stack_b);
			i++;
		}
		c++;
		printf("pa\n");
		push(&game->stack_a, &game->stack_b);

		if (*((int *) game->head->content) > *((int *) game->stack_b->content))
		 	game->head_index += 1;
	}
	return (c);
}

int	find_best_stack_a(t_game *game)
{
	int bscore = game->n;
	int bi = 0;
	int len = 0;
	t_list *elem = game->stack_a;
	while (elem)
	{
		len++;
		elem = elem->next;
	}
	int i = 0;
	while (i < len)
	{
		int s = 0;
		t_list *elem = game->stack_a;
		int j = 0;
		while (j < i)
		{
			j++;
			elem = elem->next;
		}

		if (len - i < i)
			s = len - i;
		else
			s = i;
		int pos = 0;
		t_list *elem2 = game->head;
		while (pos < (game->n - len) && *((int *) elem->content) < *((int *) elem2->content))
		{
			elem2 = elem2->next;
			if (elem2 == NULL)
				elem2 = game->stack_b;
			pos += 1;
		}
		pos = (game->head_index + pos);
		pos = pos % (game->n - len);
		s += pos;
		if (s < bscore)
		{
			printf("s = %d\n", s);
			bscore = s;
			bi = i;
		}
		i++;
	}
	
	i = 0;
	int c = 0;
	int pos = bi;
	if (len - pos < pos)
	{
		
		while (i < len - pos)
		{
			c++;
			reverse_rotate(&game->stack_a);
			i++;
		}
	}
	else
	{	
		while (i < pos)
		{
			c++;
			rotate(&game->stack_a);
			i++;
		}
	}
	return (c);
}

void sorting(t_game *game)
{
	int end = 1;
	int pos = 0;
	int c = 0;
	int i = 0;
	t_list* elem;

	
	push(&game->stack_a, &game->stack_b);
	game->head = game->stack_b;
	game->head_index = 0;
	c++;
	printf("pb\n");
	while (end < game->n)
	{
		i = 0;
		c += find_best_stack_a(game);
		game->head = game->stack_b;
		while (i < game->head_index)
		{
			i++;
			game->head = game->head->next;
		}
		elem = game->head;
		pos = 0;
		while (pos < end &&  *((int *) game->stack_a->content) < *((int *) elem->content))
		{
			elem = elem->next;
			if (elem == NULL)
				elem = game->stack_b;
			pos += 1;
		}
		pos = (game->head_index + pos);
		c += insert(game, pos);
		end += 1;
	}
	end = 0;
	while (end < game->n)
	{
		printf("pa\n");
		c++;
		push(&game->stack_b, &game->stack_a);
		end++;
	}
	
	printf("c = %d\n", c);
}

int main()
{
	t_game game;
	int	data[100] = {47,67,45,2,76,43,53,86,1,37,96,63,33,10,69,71,48,52,15,68,99,26,24,51,6,77,36,13,14,25,27,62,93,64,49,28,22,87,46,72,70,92,44,8,23,65,95,12,84,88,4,42,55,74,18,29,57,56,34,81,40,58,85,35,73,39,38,91,61,89,98,31,30,5,97,20,19,80,21,3,59,90,60,0,7,94,9,41,66,79,17,75,100,83,54,82,16,50,11,78};
	
	game = setup(data);
	print_game(game);
	printf("sorting:\n");
	//insert(&game, 3);
	sorting(&game);
	print_game(game);
	return (0);
}