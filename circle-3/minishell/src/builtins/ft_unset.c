/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:53:53 by lrondia           #+#    #+#             */
/*   Updated: 2022/06/28 14:05:50 by hakermad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_from_env(t_data *data, t_list **env, int i)
{
	t_list	*previous;
	t_list	*current;
	t_list	*next;

	previous = ft_lstget(*env, i - 1);
	current = ft_lstget(*env, i);
	next = ft_lstget(*env, i + 1);
	if (previous && next)
		previous->next = next;
	else if (previous && !next)
		previous->next = NULL;
	else if (!previous && next)
		current = next;
	else
		current = NULL;
	data->len_env--;
}

void	ft_unset(t_data *data, t_list **env)
{
	int		i;
	int		arg_count;

	arg_count = 1;
	while (data->elements[arg_count])
	{
		i = cmp_env(data, env, arg_count);
		if (i != data->len_env)
			unset_from_env(data, env, i);
		arg_count++;
	}
}
