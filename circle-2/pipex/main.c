/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:52:08 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/11 16:59:06 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	write_error(char *message)
{
	int	len;

	len = ft_strlen(message);
	write(2, message, len);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		exit_code;

	setup_pipex(&pipex, argc, argv, envp);
	exit_code = run_pipex(&pipex);
	return (exit_code);
}
