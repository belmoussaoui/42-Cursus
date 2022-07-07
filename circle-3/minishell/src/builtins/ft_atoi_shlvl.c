/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_shlvl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:24:55 by mliban-s          #+#    #+#             */
/*   Updated: 2022/06/27 16:38:31 by hakermad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	invalid_lvl(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	ft_skip_spacenl(const char *str, int *i)
{
	while ((str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n')
		|| (str[*i] == '\r' || str[*i] == '\v' || str[*i] == '\f'))
		(*i)++;
}

static int	handle_overflow(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi_shlvl(const char *str)
{
	int			sign;
	long long	res;
	int			i;

	sign = 1;
	i = 0;
	res = 0;
	ft_skip_spacenl(&str[i], &i);
	if (invalid_lvl(str))
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (res < 0)
			return (handle_overflow(sign));
	}
	return (res * sign);
}
