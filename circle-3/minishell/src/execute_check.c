/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:04:33 by lrondia           #+#    #+#             */
/*   Updated: 2022/06/30 16:52:32 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_command(char *command)
{
	if (!command)
		exit(EXIT_FAILURE);
}

void	check_cmd(char *cmd)
{
	if (cmd[0] == '/')
		print_x_error(cmd, ": No such file or directory", 127);
}
