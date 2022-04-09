/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:57:03 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/09 16:47:49 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char	*find_path_value(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

void set_path(t_pipex *pipex, char **envp)
{
	char	*value;

	value = find_path_value(envp);
	pipex->path = ft_split(value, ':');
}


void	setup_pipex(t_pipex *pipex, int argc, char** argv, char**envp)
{
	if (argc != 5)
		exit(1);
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[4], O_WRONLY);
	pipe(pipex->pipe);
	pipex->envp = envp;
	pipex->command1 =  ft_split(argv[2], ' ');
	pipex->command2 =  ft_split(argv[3], ' ');
	set_path(pipex, envp);
}
