/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:52:58 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/23 19:03:12 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	check_arg(char *arg)
{
	int				i;
	unsigned long	res;

	i = 0;
	res = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			exit_message("args is not a number", EXIT_FAILURE);
		res = res * 10 + arg[i] - '0';
		i++;
		if (res > INT_MAX)
			exit_message("args is too large", EXIT_FAILURE);
	}
	return (res);
}