/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:39:56 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/20 16:51:04 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_heredoc(t_pipex *pipex)
{
	return (ft_strncmp(pipex->argv[1], "here_doc", ft_strlen("here_doc")) == 0);
}

void	setup_heredoc(t_pipex *pipex)
{
	char	*line;

	pipex->cmdn = pipex->argc - 4;
	if (pipex->cmdn < 2)
		write_error("the number of arguments is invalid", EXIT_FAILURE);
	pipex->infile = open(".heredoc", O_CREAT | O_TRUNC | O_RDWR, 00644);
	if (pipex->infile < 0)
		exit(EXIT_FAILURE);
	while (42)
	{
		line = get_next_line(0);
		if (line == NULL)
			exit(EXIT_FAILURE);
		if (ft_strncmp(pipex->argv[2], line, ft_strlen(pipex->argv[2])) == 0
			&& ft_strlen(pipex->argv[2]) == ft_strlen(line) - 1)
			break ;
		write(pipex->infile, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(pipex->infile);
	pipex->outfile = open(".heredoc", O_CREAT | O_APPEND | O_WRONLY, 00644);
	if (pipex->outfile < 0)
		exit(EXIT_FAILURE);
}

void	setup_files(t_pipex *pipex, int argc, char **argv)
{
	pipex->cmdn = pipex->argc - 3;
	if (pipex->cmdn <= 1)
		write_error("the number of arguments is invalid", EXIT_FAILURE);
	pipex->infile = open(pipex->argv[1], O_RDONLY);
	if (pipex->infile < 0)
		write_error("missing input file", EXIT_FAILURE);
	pipex->outfile = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 00644);
	if (pipex->outfile < 0)
		exit(EXIT_FAILURE);
}
