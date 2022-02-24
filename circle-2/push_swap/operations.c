/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:38:09 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/24 18:27:09 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **out, t_list **in)
{
	t_list *elem;

	elem = *out;
	*out = elem->next;
	ft_lstadd_front(in, elem);
}

void	swap(t_list **lst)
{
	t_list *first;
	t_list *second;

	first = *lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
}

void	rotate(t_list **lst)
{
	t_list *first;
	t_list *last;

	first = *lst;
	last = ft_lstlast(first);
	last->next = *lst;
	*lst = first->next;
	first->next = NULL;
}

void	reverse_rotate(t_list **lst)
{
	int		len;
	t_list	*before;
	t_list	*last;

	len = ft_lstlen(*lst);
	before = ft_lstget(len - 1);
	last = before->next;
	before->next = NULL;
	last->next = *lst;
	*lst = last;
}