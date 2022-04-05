/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:52:08 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/05 19:25:40 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char** argv, char **envp)
{
	(void)	argc;
	(void)	argv;
	t_pipex	pipex;

	setup_pipex(&pipex, argc, argv, envp);
	run_pipex(&pipex);
	return (0);
}