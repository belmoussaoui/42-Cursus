/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:02:34 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/05 19:36:28 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void run_child1(t_pipex *pipex)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		dup2(pipex->pipe[1], 1);
		close(pipex->pipe[0]);
		close(pipex->pipe[1]);
		execlp("cat", "cat", "main.c", NULL);
	}
}

void run_child2(t_pipex *pipex)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		dup2(pipex->pipe[0], 0);
		dup2(pipex->outfile, 1);
		close(pipex->pipe[0]);
		close(pipex->pipe[1]);
		execlp("grep", "grep", "pipex", NULL);
	}
}

void	run_pipex(t_pipex *pipex)
{
	run_child1(pipex);
	run_child2(pipex);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}
