/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:39:56 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/18 17:59:38 by bel-mous         ###   ########.fr       */
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
	pipex->infile = open(".heredoc", O_CREAT | O_TRUNC | O_WRONLY, 00644);
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
	pipex->infile = open(".heredoc", O_RDONLY, 00644);
	if (pipex->infile < 0)
		exit(EXIT_FAILURE);
}
