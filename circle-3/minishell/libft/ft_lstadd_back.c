/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:16:49 by bel-mous          #+#    #+#             */
/*   Updated: 2022/06/06 16:47:48 by hakermad         ###   ########.fr       */
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
