/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:02:34 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/17 14:10:47 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if (is_heredoc(pipex))
		args = ft_split(pipex->argv[3 + index], ' ');
	else
		args = ft_split(pipex->argv[2 + index], ' ');
	if (!args)
		exit(EXIT_FAILURE);
	command = get_command(pipex, args[0]);
	if (command == NULL)
		write_error("command not found", 127);
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

int	terminate_pipex(int *pids, t_pipex *pipex)
{
	int	i;
	int	exit_code;

	i = 0;
	close_pipes(pipex);
	while (i++ < pipex->cmdn)
	{
		if (i == pipex->cmdn)
			waitpid(pids[i - 1], &exit_code, 0);
		else
			waitpid(pids[i - 1], NULL, 0);
	}
	close(pipex->infile);
	close(pipex->outfile);
	free_char_array(pipex->path);
	free(pipex->pipes);
	free(pids);
	return (WEXITSTATUS(exit_code));
}

int	run_pipex(t_pipex *pipex)
{
	int	*pids;
	int	i;

	i = 0;
	pids = malloc(sizeof(int) * pipex->cmdn);
	if (!pids)
		exit(EXIT_FAILURE);
	while (i < pipex->cmdn)
	{
		pids[i] = fork();
		if (pids[i] < 0)
			exit(EXIT_FAILURE);
		if (pids[i] == 0)
			run_child(pipex, i);
		i++;
	}
	return (terminate_pipex(pids, pipex));
}
