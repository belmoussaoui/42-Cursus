/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:37:32 by mliban-s          #+#    #+#             */
/*   Updated: 2022/06/29 13:23:49 by hakermad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	no_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	exit_code(char *message, int code)
{
	int	len;

	len = ft_strlen(message);
	g_error_code = code;
	write(2, message, len);
	write(2, "\n", 1);
	exit(g_error_code);
}

void	ft_exit(t_data *data)
{
	int	arg_count;

	arg_count = 0;
	while (data->elements[arg_count])
		arg_count++;
	if (arg_count > 1)
	{
		if (!no_digit(data->elements[1]))
			exit_code("exit: abc: numeric argument required", 255);
		if (arg_count > 2)
			exit_code("too many arguments", 1);
		else
			g_error_code = ft_atoi(data->elements[1]);
		exit_code("exit", g_error_code);
	}
	exit_code("exit", 0);
}
