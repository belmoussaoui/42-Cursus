/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:57:03 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/13 23:24:51 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_pipex(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	free_char_array(pipex->path);
}

char	*find_path_value(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

void	setup_pipex(t_pipex *pipex, int argc, char **argv, char**envp)
{
	int	i;

	i = 0;

	if (argc <= 1)
		exit(1);
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		write_error("missing input file\n");
	pipex->outfile = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 00644);
	if (pipex->outfile < 0)
		exit(EXIT_FAILURE);
	pipex->pipe = malloc(sizeof(int) * ((argc - 4) * 2));

	while (i < argc - 4)
	{
		if (pipe(pipex->pipe + (i * 2)) == -1)
			exit(EXIT_FAILURE);
		printf("oki\n");
		i++;
	}

	pipex->argv = argv;
	pipex->argc = argc;
	pipex->envp = envp;
	pipex->path = ft_split(find_path_value(envp), ':');
	if ( !pipex->path)
		exit(EXIT_FAILURE);

}
