/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:02:34 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/09 18:55:11 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_command(t_pipex *pipex, char *command)
{
	int		i;
	char	*path;
	char	*slash_command;

	i = 0;
	while (pipex->path[i])
	{
		slash_command = ft_strjoin("/", command);
		path = ft_strjoin(pipex->path[i], slash_command);
		if (access(path, 0) == 0)
			return (path);
		i++;
	}
	return (NULL);
}

void	run_child1(t_pipex *pipex, int pid)
{
	char	*file;

	if (pid < 0)
	{
		exit(1);
	}
	if (pid == 0)
	{
		file = get_command(pipex, pipex->command1[0]);
		dup2(pipex->pipe[1], 1);
		dup2(pipex->infile, 0);
		close(pipex->pipe[0]);
		close(pipex->pipe[1]);
		execve(file, pipex->command1, pipex->envp);
	}
}

void	run_child2(t_pipex *pipex, int pid)
{
	char	*file;

	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		file = get_command(pipex, pipex->command2[0]);
		dup2(pipex->pipe[0], 0);
		dup2(pipex->outfile, 1);
		close(pipex->pipe[0]);
		close(pipex->pipe[1]);
		execve(file, pipex->command2, pipex->envp);
	}
}

int	run_pipex(t_pipex *pipex)
{
	int	pid1;
	int	pid2;
	int	exit_code;

	pid1 = fork();
	run_child1(pipex, pid1);
	pid2 = fork();
	run_child2(pipex, pid2);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &exit_code, 0);
	free_pipex(pipex);
	return (exit_code);
}
