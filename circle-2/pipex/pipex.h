/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:26:15 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/09 16:47:11 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipe[2];
	char	**path;
	char	**command1;
	char	**command2;
	char	**envp;
}	t_pipex;

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
void	setup_pipex(t_pipex *pipex, int argc, char** argv, char**envp);
int		run_pipex(t_pipex *pipex);
char	*ft_strjoin(char const *s1, char const *s2);

#endif