/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:43:52 by lrondia           #+#    #+#             */
/*   Updated: 2022/06/27 19:27:45 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_metachar(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

void	activate_s_quote(t_data *data, char c)
{
	if (c == '\'' && data->s_quote == 0 && data->d_quote == 0)
		data->s_quote = 1;
	else if (c == '\'' && data->s_quote == 1)
		data->s_quote = 0;
}

void	activate_d_quote(t_data *data, char c)
{
	if (c == '"' && data->d_quote == 0 && data->s_quote == 0)
		data->d_quote = 1;
	else if (c == '"' && data->d_quote == 1)
		data->d_quote = 0;
}

int	check_quote(t_data *data, char c)
{
	activate_s_quote(data, c);
	activate_d_quote(data, c);
	if (data->s_quote == 1 || data->d_quote == 1)
		return (1);
	return (0);
}

void	clear_quote(t_data *data)
{
	data->s_quote = 0;
	data->d_quote = 0;
}
