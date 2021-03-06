/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:57:03 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/22 17:42:40 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_command(t_pipex *pipex, char *command)
{
	int		i;
	char	*path;
	char	*slash_command;

	if (access(command, F_OK) == 0)
		return (command);
	i = 0;
	while (pipex->path[i])
	{
		slash_command = ft_strjoin("/", command);
		if (slash_command == NULL)
			exit(EXIT_FAILURE);
		path = ft_strjoin(pipex->path[i], slash_command);
		if (path == NULL)
			exit(EXIT_FAILURE);
		free(slash_command);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

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

void	create_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex->pipes = malloc(sizeof(int) * ((pipex->cmdn - 1) * 2));
	if (!pipex->pipes)
		exit(EXIT_FAILURE);
	while (i < pipex->cmdn - 1)
	{
		if (pipe(pipex->pipes + (i * 2)) == -1)
			exit(EXIT_FAILURE);
		i++;
	}
}

void	setup_pipex(t_pipex *pipex, int argc, char **argv, char**envp)
{
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	if (is_heredoc(pipex))
		setup_heredoc(pipex);
	else
		setup_files(pipex, argc, argv);
	pipex->path = ft_split(find_path_value(envp), ':');
	if (!pipex->path)
		exit(EXIT_FAILURE);
	create_pipes(pipex);
}
