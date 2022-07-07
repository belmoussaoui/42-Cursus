/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:14:12 by lrondia           #+#    #+#             */
/*   Updated: 2022/06/30 16:51:51 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_x_error(char *command, char *message, int code)
{
	g_error_code = code;
	write(2, command, ft_strlen(command));
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(code);
}

char	*path_finder(char **envp)
{
	while (*envp && ft_strncmp("PATH", *envp, 4))
		envp++;
	if (!*envp)
		werror_exit("No such file or directory", 127);
	return (*envp + 5);
}

void	write_permission(char *cmd_name)
{
	write(2, cmd_name, ft_strlen(cmd_name));
	werror_exit(": Permission denied", 126);
}

char	*cmd_ok(char **paths, char *cmd)
{
	char	*temp;
	char	*command;

	if (!paths || !cmd[0])
		return (NULL);
	if (opendir(cmd) && cmd[0] == '/')
		print_x_error(cmd, ": is a directory", 126);
	if (access(cmd, X_OK) == 0 && !opendir(cmd))
		return (cmd);
	else if (cmd[0] == '.' && cmd[1] == '/'
		&& access(cmd, X_OK) == -1 && errno == EACCES)
		write_permission(cmd);
	while (*paths)
	{
		temp = ft_strjoin(*paths, "/");
		command = ft_strjoin(temp, cmd);
		check_command(command);
		free(temp);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	check_cmd(cmd);
	return (NULL);
}

char	**env_list_to_tab(t_list *env)
{
	int		i;
	int		len;
	char	**env_tab;

	i = 0;
	len = ft_lstlen(env);
	env_tab = malloc(sizeof (char *) * len + 1);
	if (!env_tab)
		exit (EXIT_FAILURE);
	while (i < len)
	{
		env_tab[i] = malloc(sizeof(char)
				* ft_strlen((char *)(env->content)) + 1);
		if (!env_tab[i])
			exit (EXIT_FAILURE);
		ft_strlcpy(env_tab[i], (char *)(env->content),
			ft_strlen((char *)(env->content)) + 1);
		env = env->next;
		i++;
	}
	env_tab[i] = 0;
	return (env_tab);
}
