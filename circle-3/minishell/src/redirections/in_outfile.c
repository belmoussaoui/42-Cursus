/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_outfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:35:10 by lrondia           #+#    #+#             */
/*   Updated: 2022/06/30 12:29:15 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_infile(t_cmd *cmd, char *infile)
{
	cmd->is_infile = 0;
	cmd->fd_infile = open(infile, O_RDONLY);
	if (cmd->fd_infile == -1)
	{
		cmd->fd_infile = -2;
		write(2, infile, ft_strlen(infile));
		werror(": No such file or directory", 127);
	}
}

void	handle_outfile(t_cmd *cmd, char *outfile)
{
	cmd->is_outfile = 1;
	cmd->fd_outfile = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->fd_outfile == -1)
	{
		cmd->fd_outfile = -2;
		write(2, outfile, ft_strlen(outfile));
		werror(": No such file or directory", 127);
	}
}

void	handle_outfile_append(t_cmd *cmd, char *outfile)
{
	cmd->is_outfile = 1;
	cmd->fd_outfile = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (cmd->fd_outfile == -1)
	{
		cmd->fd_outfile = -2;
		write(2, outfile, ft_strlen(outfile));
		werror(": No such file or directory", 127);
	}
}
