/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:04:28 by bel-mous          #+#    #+#             */
/*   Updated: 2022/06/30 16:51:59 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# include <termios.h>
# include "../libft/libft.h"
# include <errno.h>
# include <dirent.h>

int		g_error_code;

typedef struct s_data
{
	int		shlvl;
	bool	s_quote;
	bool	d_quote;
	int		len_env;
	t_list	*new_env;
	char	*line;
	char	*cmd;
	char	**paths;
	char	**elements;
	t_list	*commands;
}	t_data;

typedef struct s_cmd
{
	char	**elements;
	int		infile;
	int		outfile;
	int		is_infile;
	int		is_outfile;
	int		fd_infile;
	int		fd_outfile;
}	t_cmd;

// INIT
void	initializer(t_data *data, char *envp[]);
char	*reader(t_data *data);

// PARSING
int		syntax_error(t_data *data);
int		parser(t_data *data, t_list **commands, char *line);

// REDIRECTIONS
void	redirections(t_list *commands);
void	clear_redirection(char **elements);
void	handle_heredoc(t_cmd *cmd, char *stop);
void	handle_infile(t_cmd *cmd, char *infile);
void	handle_outfile(t_cmd *cmd, char *outfile);
void	handle_outfile_append(t_cmd *cmd, char *outfile);

// EXPANDER
void	expander(t_data *data, t_list *commands);

// EXECUTION
void	print_x_error(char *command, char *message, int code);
void	execute(t_data *data);
char	*path_finder(char **envp);
char	*cmd_ok(char **paths, char *cmd_name);
char	**env_list_to_tab(t_list *env);
void	run_builtin(t_data *data, char *cmd_name);
int		is_builtin(char *cmd_name);
int		cmp_env(t_data *data, t_list **new_env, int arg_count);
char	*get_env(t_list *env, char *name);
void	add_env(t_data *data, t_list **env, char *str);

// BUILTINS
void	ft_env(t_list *env);

bool	ft_cd(t_data *data);

int		ft_pwd(void);
char	*get_pwd(void);
void	update_pwd(t_data *data, char *name);

void	ft_unset(t_data *data, t_list **new_env);

void	ft_export(t_data *data, t_list **new_env);
void	parsing_export_unset(char *line);

void	increment_shell_level(t_data *data, t_list *new_env);
int		ft_atoi_shlvl(const char *str);

bool	ft_echo(t_data *data);

// CLEAR
void	clear(t_data *data);
void	*free_split(char **strings);

void	ft_exit(t_data *data);

// UTILS

int		is_metachar(char c);
int		is_only_space(char *line);
int		check_quote(t_data *data, char c);
void	clear_quote(t_data *data);
void	ft_close(t_list *commands);
void	werror(char *message, int code);
void	werror_exit(char *message, int code);
int		ft_strcmp(char *s1, char *s2);
char	*join_the_split(char **split);
char	**ft_split_quote(t_data *data, char const *s);
char	**ft_split_redirections(t_data *data, char **s);
int		is_parent_cmd(char *cmd_name);

void	check_command(char *command);
void	check_cmd(char *cmd);

// DEBUG

void	debug_list(t_list *commands);
void	debug_env(t_list *env);
void	debug_split(char **split);

// SIGNAL
void	run_signals(int sig);
void	rl_replace_line(const char *text, int clear_undo);
void	term_config(void);

#endif