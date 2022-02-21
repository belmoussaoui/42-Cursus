/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:38:09 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/20 15:31:29 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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


void	push(t_list **out, t_list **in)
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
	t_list *first = *lst;
	t_list *last = ft_lstlast(first);
	last->next = *lst;
	*lst = first->next;
	first->next = NULL;
}

void	reverse_rotate(t_list **lst)
{
	t_list *before = ft_lstbefore(*lst);
	t_list *last = before->next;
	before->next = NULL;
	last->next = *lst;
	*lst = last;
}