/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:01:14 by bel-mous          #+#    #+#             */
/*   Updated: 2022/06/24 16:28:52 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_commands(t_list *commands)
{
	int		i;
	t_cmd	*content;

	while (commands)
	{
		i = 0;
		content = (t_cmd *)(commands->content);
		free_split(content->elements);
		free(content);
		free(commands);
		commands = commands->next;
	}
}

void	clear(t_data *data)
{
	free_commands(data->commands);
	if (data->line)
		free(data->line);
	data->commands = NULL;
	data->s_quote = 0;
	data->d_quote = 0;
}
