/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:52:08 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/09 13:37:55 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char** argv, char **envp)
{
	t_pipex	pipex;
	int		exit_code;

	setup_pipex(&pipex, argc, argv, envp);
	exit_code = run_pipex(&pipex);
	return (exit_code);
}