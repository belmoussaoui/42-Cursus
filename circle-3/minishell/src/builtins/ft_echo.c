/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:20:33 by hakermad          #+#    #+#             */
/*   Updated: 2022/06/29 21:13:14 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_option_n(char *options)
{
	int	i;

	i = 0;
	if (options[0] != '-')
		return (false);
	while (options[i])
	{
		if (options[i] == 'n')
			return (true);
		i++;
	}
	return (false);
}

bool	ft_echo(t_data *data)
{
	int	i;
	int	is_options_mode;

	is_options_mode = 0;
	if (!data->elements || ft_strcmp("echo", *data->elements))
		return (true);
	i = 1;
	while (data->elements[i])
	{
		if (!is_option_n(data->elements[i]) || is_options_mode)
		{
			printf("%s", data->elements[i]);
			is_options_mode = 1;
		}
		if (data->elements[i + 1] && !is_option_n(data->elements[i]))
			printf(" ");
		i++;
	}
	if (!is_option_n(data->elements[1]))
		printf("\n");
	return (false);
}
