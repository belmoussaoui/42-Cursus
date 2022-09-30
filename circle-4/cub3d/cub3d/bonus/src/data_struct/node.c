/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:26:00 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/27 02:41:20 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_node	*new_node(void *content)
{
	t_node	*node;

	node = x_malloc(sizeof(t_node));
	ft_memset(node, 0, sizeof(t_node));
	node->content = content;
	return (node);
}
