/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:26:15 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/20 17:18:38 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../utils/ft_utils.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		*pipes;
	int		cmdn;
	char	**argv;
	char	**path;
	char	**envp;
}	t_pipex;

void	setup_pipex(t_pipex *pipex, int argc, char **argv, char **envp);
int		run_pipex(t_pipex *pipex);
void	free_char_array(char **array);
void	write_error(char *message, int code);
char	*get_command(t_pipex *pipex, char *command);
void	exit_perror(char *message);

#endif