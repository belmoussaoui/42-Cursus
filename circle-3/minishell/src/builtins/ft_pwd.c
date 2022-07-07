/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:38:03 by hakermad          #+#    #+#             */
/*   Updated: 2022/06/29 22:20:18 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_pwd(t_data *data, char *name)
{
	char	*content;
	int		len_name;
	t_list	*env;
	char	*path;

	env = data->new_env;
	len_name = ft_strlen(name);
	while (env)
	{
		content = (char *) env->content;
		if (!ft_strncmp(name, content, len_name))
		{
			path = get_pwd();
			env->content = ft_strjoin(name, path);
			if (!content)
				exit(EXIT_FAILURE);
			free(path);
			break ;
		}
		env = env->next;
	}
}

char	*get_pwd(void)
{
	char	*direction;

	direction = NULL;
	direction = getcwd(direction, 0);
	if (!direction)
		printf("Error pwd\n");
	return (direction);
}

int	ft_pwd(void)
{
	char	*direction;

	direction = get_pwd();
	printf("%s\n", direction);
	free(direction);
	return (0);
}
