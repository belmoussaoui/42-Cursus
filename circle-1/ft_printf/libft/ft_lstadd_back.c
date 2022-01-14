/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:16:49 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/11 08:29:41 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstlast;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		ft_lstadd_front(lst, new);
	else
	{
		lstlast = ft_lstlast(*lst);
		if (lstlast)
			lstlast->next = new;
	}
}
