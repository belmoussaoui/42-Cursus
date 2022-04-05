/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:57:03 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/05 18:59:53 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void set_path(t_pipex *pipex, char **envp)
{
	(void)	envp;
	(void)	pipex;
}

void	setup_pipex(t_pipex *pipex, int argc, char** argv, char**envp)
{
	if (argc != 5)
		exit(1);
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[4], O_WRONLY);
	pipe(pipex->pipe);
	set_path(pipex, envp);
}
