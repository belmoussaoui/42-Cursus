/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:02:34 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/13 23:41:47 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_command(t_pipex *pipex, char *command)
{
	int		i;
	char	*path;
	char	*slash_command;

	i = 5;
	while (pipex->path[i])
	{
		
		slash_command = ft_strjoin("/", command);
		if (slash_command == NULL)
			exit(EXIT_FAILURE);
		path = ft_strjoin(pipex->path[i], slash_command);
		if (path == NULL)
			exit(EXIT_FAILURE);
		if (access(path, 0) == 0)
			return (path);
		free(path);
		free(slash_command);
		i--;
	}
	if (access(command, 0) == 0)
		return (command);
	return (NULL);
}

void	run_child1(t_pipex *pipex, int pid, int index)
{
	char	*command;
	char	**args;
	int i = 0;

	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		args = ft_split(pipex->argv[2 + index], ' ');
		command = get_command(pipex, args[0]);
		if (command == NULL)
			write_error("command not found\n");
		if (index == 0)
		{
			dup2(pipex->infile, 0);
			dup2(pipex->pipe[1], 1);
			while (i < (pipex->argc - 4))
			{
				close(pipex->pipe[i * 2]);
				close(pipex->pipe[i * 2 + 1]);
				i++;
			}
		} else if (index == pipex->argc - 4) {
			printf("end = %d\n", index * 2 - 2);
			dup2(pipex->pipe[index * 2 - 2], 0);
			dup2(pipex->outfile, 1);
			while (i < (pipex->argc - 4))
			{
				close(pipex->pipe[i * 2]);
				close(pipex->pipe[i * 2 + 1]);
				i++;
			}
		} else {
			dup2(pipex->pipe[index * 2 - 2], 0);
			dup2(pipex->pipe[index * 2 + 1], 1);
			while (i < (pipex->argc - 4))
			{
				close(pipex->pipe[i * 2]);
				close(pipex->pipe[i * 2 + 1]);
				i++;
			}
		}
		if (execve(command, args, pipex->envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
}

int	run_pipex(t_pipex *pipex)
{
	int	pid1;
	int	exit_code;
	int i = 0;

	
	while (i < pipex->argc - 3)
	{
		pid1 = fork();
		run_child1(pipex, pid1, i);
		i++;
	}
//	close(pipex->pipe[0]);
//	close(pipex->pipe[1]);
//	close(pipex->pipe[2]);
	//close(pipex->pipe[3]);
	waitpid(-1, NULL, 0);
	free_pipex(pipex);
	return (WEXITSTATUS(exit_code));
}
