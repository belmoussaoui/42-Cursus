/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:42:11 by lrondia           #+#    #+#             */
/*   Updated: 2022/06/30 01:15:13 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_fd(t_cmd *cmd, char **elements, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '<' && line[i] != '>')
		i++;
	if (line[i] && line[i] == '<' && line[i + 1] == '<')
		handle_heredoc(cmd, elements[1]);
	else if (line[i] && line[i] == '<' && line[i + 1] != '<'
		&& line[i + 1] == '\0')
		handle_infile(cmd, elements[1]);
	else if (line[i] && line[i] == '>' && line[i + 1] != '>'
		&& line[i + 1] == '\0')
		handle_outfile(cmd, elements[1]);
	else if (line[i] && line[i] == '>' && line[i + 1] == '>')
		handle_outfile_append(cmd, elements[1]);
}

void	redirections(t_list *commands)
{
	int		i;
	t_cmd	*content;

	while (commands)
	{
		i = 0;
		content = (t_cmd *)(commands->content);
		while (content->elements[i])
		{
			handle_fd(content, content->elements + i,
				content->elements[i]);
			i++;
		}
		clear_redirection(content->elements);
		unlink(".heredoc");
		commands = commands->next;
	}
}
