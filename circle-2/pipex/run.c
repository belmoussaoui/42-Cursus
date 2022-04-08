/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:02:34 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/08 18:54:43 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void run_child1(t_pipex *pipex, int pid)
{
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

void run_child2(t_pipex *pipex, int pid)
{
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		dup2(pipex->pipe[0], 0);
		dup2(pipex->outfile, 1);
		close(pipex->pipe[0]);
		close(pipex->pipe[1]);
		execlp("grepdjksfh", "grepdios", "run", NULL);
		exit(1);
	}
}

void	run_pipex(t_pipex *pipex)
{
	int	pid1;
	int	pid2;
	int test;

	pid1 = fork();
	run_child1(pipex, pid1);
	pid2 = fork();
	run_child2(pipex, pid2);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &test, 0);
	printf("%i\n", WEXITSTATUS(test));
	
}
