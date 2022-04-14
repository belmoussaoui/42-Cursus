/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:02:34 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/14 19:41:36 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_command(t_pipex *pipex, char *command)
{
	int		i;
	char	*path;
	char	*slash_command;

	if (access(command, X_OK) == 0)
		return (command);
	i = 5;
	while (pipex->path[i])
	{
		slash_command = ft_strjoin("/", command);
		if (slash_command == NULL)
			exit(EXIT_FAILURE);
		path = ft_strjoin(pipex->path[i], slash_command);
		if (path == NULL)
			exit(EXIT_FAILURE);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		free(slash_command);
		i--;
	}
	return (NULL);
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->cmdn - 1))
	{
		close(pipex->pipes[i * 2]);
		close(pipex->pipes[i * 2 + 1]);
		i++;
	}
}

void	handle_pipe(int fd1, int fd2, t_pipex *pipex)
{
	dup2(fd1, 0);
	dup2(fd2, 1);
	close_pipes(pipex);
}

void	run_child(t_pipex *pipex, int index)
{
	char	*command;
	char	**args;
	int		*pipes;

	pipes = pipex->pipes;
	args = ft_split(pipex->argv[2 + index], ' ');
	if (!args)
		exit(EXIT_FAILURE);
	command = get_command(pipex, args[0]);
	if (command == NULL)
		write_error("command not found\n");
	if (index == 0)
		handle_pipe(pipex->infile, pipes[1], pipex);
	else if (index == pipex->cmdn - 1)
		handle_pipe(pipes[index * 2 - 2], pipex->outfile, pipex);
	else
		handle_pipe(pipes[index * 2 - 2], pipes[index * 2 + 1], pipex);
	if (execve(command, args, pipex->envp) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

int	run_pipex(t_pipex *pipex)
{
	int	pid;
	int	exit_code;
	int	i;

	i = 0;
	while (i < pipex->cmdn)
	{
		pid = fork();
		if (pid < 0)
			exit(EXIT_FAILURE);
		if (pid == 0)
			run_child(pipex, i);
		i++;
	}
	i = 0;
	close_pipes(pipex);
	while (i++ < pipex->cmdn)
	{
		if (i == pipex->cmdn)
			waitpid(-1, NULL, 0);
		else
			waitpid(-1, &exit_code, 0);
	}
	close(pipex->infile);
	close(pipex->outfile);
	free_char_array(pipex->path);
	free(pipex->pipes);
	return (WEXITSTATUS(exit_code));
}
