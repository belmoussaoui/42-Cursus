/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:53:49 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/05 16:49:48 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	ft_open(int filedes[2])
{
 	filedes[0] = open("in", O_RDONLY);
	filedes[1] = open("out", O_WRONLY);
 	return (0);
}

void	pipex()
{
	int	fds[2];
	int	files[2];
	int	pid1;
	int	pid2;

	ft_open(files);
	if (pipe(fds) != 0)
		exit(1);
	pid1 = fork();
	if (pid1 < 0)
		exit(1);
	if (pid1 == 0)
	{
		dup2(fds[1], 1);
		close(fds[0]);
		close(fds[1]);
		execlp("cat", "cat", "main.c", NULL);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fds[0], 0);
		dup2(files[1], 1);
		close(fds[0]);
		close(fds[1]);
		execlp("grep", "grep", "pipex", NULL);
	}
	close(fds[0]);
	close(fds[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main()
{
	pipex();
	return (0);
}
