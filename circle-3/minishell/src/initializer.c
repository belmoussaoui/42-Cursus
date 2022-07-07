/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 03:05:53 by bel-mous          #+#    #+#             */
/*   Updated: 2022/06/28 15:06:03 by hakermad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(t_data *data, t_list **new_env, char *envp[])
{
	int	i;

	i = 0;
	while (envp[data->len_env])
		data->len_env++;
	while (i < data->len_env)
	{
		ft_lstadd_back(new_env, ft_lstnew(envp[i]));
		i++;
	}
}

// Intialize minishell data and setup the environment.
void	initializer(t_data *data, char *envp[])
{
	char	*shlvl;

	data->shlvl = 0;
	data->s_quote = 0;
	data->d_quote = 0;
	data->commands = NULL;
	data->len_env = 0;
	data->new_env = NULL;
	g_error_code = 0;
	init_env(data, &data->new_env, envp);
	shlvl = get_env(data->new_env, "SHLVL");
	if (!shlvl)
		add_env(data, &data->new_env, "SHLVL=1");
	else
		increment_shell_level(data, data->new_env);
}
