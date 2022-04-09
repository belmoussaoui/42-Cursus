/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:57:03 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/09 18:48:28 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_pipex(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	free_char_array(pipex->command1);
	free_char_array(pipex->command2);
	free_char_array(pipex->path);
}

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

void	set_path(t_pipex *pipex, char **envp)
{
	char	*value;

	value = find_path_value(envp);
	pipex->path = ft_split(value, ':');
}

void	setup_pipex(t_pipex *pipex, int argc, char **argv, char**envp)
{
	if (argc != 5)
		exit(1);
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		exit(EXIT_SUCCESS);
	pipex->outfile = open(argv[4], O_WRONLY);
	if (pipex->outfile < 0)
	{
		close(pipex->infile);
		exit(EXIT_SUCCESS);
	}
	if (pipe(pipex->pipe) == -1)
	{
		free_pipex(pipex);
		exit(EXIT_SUCCESS);
	}
	pipex->envp = envp;
	pipex->command1 = ft_split(argv[2], ' ');
	pipex->command2 = ft_split(argv[3], ' ');
	set_path(pipex, envp);
	if (!pipex->command1 || !pipex->command2 || !pipex->path)
	{
		free_pipex(pipex);
		exit(EXIT_FAILURE);
	}
}
