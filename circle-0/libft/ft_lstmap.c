/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:28:45 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/10 17:42:53 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**start;
	t_list	*lstnew;

	if (lst == NULL)
		return (NULL);
	lstnew = ft_lstnew(f(lst->content));
	start = &lstnew;
	while (lst)
	{
		lstnew = ft_lstnew(f(lst->content));
		if (lstnew == NULL)
		{
			ft_lstclear(start, del);
			return (NULL);
		}
		ft_lstadd_back(start, lstnew);
		lst = lst->next;
	}
	return (*start);
}
