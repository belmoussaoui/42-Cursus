/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:36:17 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/07 00:42:54 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

static int	handle_overflow(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	res;
	int			i;

	sign = 1;
	i = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
		if (res < 0)
			return (handle_overflow(sign));
	}
	return (res * sign);
}
