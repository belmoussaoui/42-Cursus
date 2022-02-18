/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:17:11 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/18 20:05:52 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	printlst(t_list *lst)
{
	while (lst)
	{
		printf("%d ", *((int *) lst->content));
		lst = lst->next;
	}
	printf("\n");
}

void	initialize_stack(t_list **stack, int data[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_lstadd_back(stack, ft_lstnew(data + i));
		i++;
	}
}

t_list	*ft_lstbefore(t_list *lst)
{
	t_list* before;

	if (lst == NULL)
		return (NULL);
	before = NULL;
	while (lst->next)
	{
		before = lst;
		lst = lst->next;
	}
	return (before);
}

void	push(t_list **in, t_list **out)
{
	t_list *elem = *out;
	*out = elem->next;
	ft_lstadd_front(in, elem);
}

void	swap(t_list **lst)
{
	t_list *first = *lst;
	t_list *second = first->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
}

void	rotate(t_list **lst)
{
	t_list *before = ft_lstbefore(*lst);
	t_list *last = before->next;
	before->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	reverse_rotate(t_list **lst)
{
	t_list *first = *lst;
	t_list *last = ft_lstlast(first);
	last->next = *lst;
	*lst = first->next;
	first->next = NULL;
}

void	sorting(t_list** stack_a, t_list** stack_b)
{
	int end = 1;
	int pos = 0;
	t_list* elem;
	push(stack_b, stack_a);
	printf("pb\n");
	while (end < 5)
	{
		push(stack_b, stack_a);
		printf("pb\n");
		elem = *stack_b;
		pos = end - 1;
		while (pos >= 0 &&  *((int *) elem->content) < *((int *) elem->next->content))
		{
			swap(stack_b);
			printf("sb\n");
			reverse_rotate(stack_b);
			printf("rrb\n");
			pos -= 1;
		}
		while (end - 1 > pos)
		{
			rotate(stack_b);
			printf("rb\n");
			pos += 1;
		}
		end += 1;
	}
}


int main()
{
	int	data[5] = {1, 5, 2, 4, 3};
	t_list* stack_a;
	t_list* stack_b;
	stack_a = NULL;
	stack_b = NULL;
	initialize_stack(&stack_a, data, 5);
	printlst(stack_a);
	sorting(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	printf("pa\n");
	printf("pa\n");
	printf("pa\n");
	printf("pa\n");
	printf("pa\n");
	printlst(stack_a);
	return (0);
}

