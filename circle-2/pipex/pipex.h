/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:26:15 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/14 15:25:04 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

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

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

void	setup_pipex(t_pipex *pipex, int argc, char **argv, char **envp);
int		run_pipex(t_pipex *pipex);
void	free_char_array(char **array);
void	write_error(char *message);
char	*get_command(t_pipex *pipex, char *command);

#endif