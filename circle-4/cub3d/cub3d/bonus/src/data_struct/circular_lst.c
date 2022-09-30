/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:23:08 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/27 04:09:56 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clst_add_back(t_list *lst, t_node *node)
{
	if (lst && node)
	{
		if (!lst->head)
		{
			lst->head = node;
			node->prev = node;
			node->next = node;
		}
		else
		{
			lst->head->prev->next = node;
			node->prev = lst->head->prev;
			lst->head->prev = node;
			node->next = lst->head;
		}
	}
}

void	clst_rotate(t_list *lst)
{
	if (lst && lst->head)
		lst->head = lst->head->next;
}

size_t	clst_size(t_list lst)
{
	size_t	i;
	t_node	*node;

	i = 0;
	node = lst.head;
	while (node && (node != lst.head || !i))
	{
		node = node->next;
		i++;
	}
	return (i);
}

void	clst_clear(t_list *lst, void (*del)(void*))
{
	t_node	*node;
	t_node	*next;
	size_t	len;
	size_t	i;

	if (lst)
	{
		len = clst_size(*lst);
		node = lst->head;
		i = 0;
		while (i < len)
		{
			next = node->next;
			del(node->content);
			free(node);
			node = next;
			i++;
		}	
	}
}
