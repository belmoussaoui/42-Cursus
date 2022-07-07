/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:34:39 by lrondia           #+#    #+#             */
/*   Updated: 2022/06/30 12:26:09 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_command(t_data *data, char *line)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = 0;
	if (!line)
		return (line);
	while (line[len] && ((check_quote(data, line[len])
				&& line[len] == '|') || line[len] != '|'))
		len++;
	tmp = malloc(sizeof(char) * len + 1);
	if (!tmp)
		exit(EXIT_FAILURE);
	while (i < len)
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = '\0';
	clear_quote(data);
	return (tmp);
}

void	fd_pipe(t_cmd *cmd)
{
	int		tab[2];

	if (pipe(tab) == -1)
		werror_exit("can't pipe, error occured\n", 127);
	cmd->infile = tab[0];
	cmd->outfile = tab[1];
}

void	lexer(t_data *data, t_list **commands, char *line)
{
	t_list	*new;
	t_cmd	*cmd;
	char	*tmp;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		exit(EXIT_FAILURE);
	tmp = get_command(data, line);
	cmd->elements = ft_split_quote(data, tmp);
	cmd->elements = ft_split_redirections(data, cmd->elements);
	fd_pipe(cmd);
	cmd->is_infile = -1;
	cmd->is_outfile = -1;
	new = ft_lstnew(cmd);
	if (!new)
		exit(EXIT_FAILURE);
	ft_lstadd_back(commands, new);
	free(tmp);
}

// Transforms a command line into a list of tokens
int	parser(t_data *data, t_list **commands, char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	lexer(data, commands, line);
	while (line[i])
	{
		if (!check_quote(data, line[i]) && line[i] == '|')
			lexer(data, commands, line + i + 1);
		i++;
	}
	redirections(*commands);
	clear_quote(data);
	return (1);
}
