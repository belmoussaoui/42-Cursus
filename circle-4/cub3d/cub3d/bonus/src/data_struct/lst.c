/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:35:50 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/21 18:23:47 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	lst_add_front(t_list *lst, t_node *new_node)
{
	if (lst && new_node)
	{
		new_node->next = lst->head;
		new_node->prev = NULL;
		if (lst->head)
			lst->head->prev = new_node;
		lst->head = new_node;
	}
}

void	lst_clear(t_list *lst, void (*del)(void*))
{
	t_node	*node;
	t_node	*next;

	if (lst)
	{
		node = lst->head;
		while (node)
		{
			next = node->next;
			del(node->content);
			free(node);
			node = next;
		}		
	}
}
