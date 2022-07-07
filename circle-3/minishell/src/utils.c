/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:08:51 by hakermad          #+#    #+#             */
/*   Updated: 2022/06/30 12:40:44 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_the_split(char **split)
{
	int		i;
	char	*copy;
	char	*str;

	i = 0;
	str = "";
	while (split[i])
	{
		copy = ft_strjoin(str, split[i]);
		if (!copy)
			exit(EXIT_FAILURE);
		str = copy;
		free(copy);
		i++;
	}
	return (str);
}

int	is_only_space(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
		|| line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
		i++;
	if (i == ft_strlen(line))
		return (1);
	return (0);
}

void	werror(char *message, int code)
{
	int	len;

	len = ft_strlen(message);
	g_error_code = code;
	write(2, message, len);
	write(2, "\n", 1);
}

void	werror_exit(char *message, int code)
{
	int	len;

	len = ft_strlen(message);
	g_error_code = code;
	write(2, message, len);
	write(2, "\n", 1);
	exit(code);
}

void	ft_close(t_list *commands)
{
	int		i;
	t_list	*copy;

	i = 0;
	copy = commands;
	while (copy)
	{
		close(((t_cmd *)(copy->content))->infile);
		close(((t_cmd *)(copy->content))->outfile);
		if (((t_cmd *)(copy->content))->is_infile != -1)
			close(((t_cmd *)(copy->content))->fd_infile);
		if (((t_cmd *)(copy->content))->is_outfile != -1)
			close(((t_cmd *)(copy->content))->fd_outfile);
		copy = copy->next;
	}
}
