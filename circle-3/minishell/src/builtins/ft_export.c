/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:45:10 by mliban-s          #+#    #+#             */
/*   Updated: 2022/06/29 19:13:02 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsing_export_unset(char *line)
{
	int		i;
	char	c;

	i = 0;
	if (ft_isdigit(line[i]))
		werror("export: not a valid identifier", 1);
	while (line[i])
	{
		c = line[i];
		if (!ft_isalnum(c) && c != '_' && c != '=')
			werror("export: not a valid identifier", 1);
		i++;
	}
}

void	add_env(t_data *data, t_list **env, char *str)
{
	ft_lstadd_back(env, ft_lstnew(ft_strdup(str)));
	data->len_env++;
}

void	ft_export(t_data *data, t_list **new_env)
{
	int		i;
	int		arg_count;

	arg_count = 1;
	if (!data->elements[arg_count])
		ft_env(*new_env);
	while (data->elements[arg_count])
	{
		i = cmp_env(data, new_env, arg_count);
		if (!ft_strchr(data->elements[arg_count], '=') || g_error_code)
		{
			arg_count++;
			continue ;
		}
		else if (i == data->len_env)
			add_env(data, new_env, data->elements[arg_count]);
		else
			(ft_lstget(*new_env, i))->content =
				ft_strdup(data->elements[arg_count]);
		arg_count++;
	}
}
