/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:39:28 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/24 22:29:24 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	atoui8_error(const char *s, uint8_t *n)
{
	int			sum;

	sum = 0;
	while (ft_strchr(SPACES, *s))
		s++;
	while (*s >= '0' && *s <= '9')
	{
		sum *= 10;
		sum += *s - '0';
		if (sum > 255)
			return (true);
		s++;
	}
	if (n)
		*n = sum;
	return (!ft_strchr(" \t\n\r\v\f", *s) && *s);
}

int	isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	uint64_t	sum;
	int			sign;

	sum = 0;
	sign = 1;
	while (ft_strchr(" \t\n\r\v\f", *str))
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign = -1;
	while (isdigit(*str))
	{
		sum *= 10;
		sum += *str - '0';
		str++;
	}
	if (sum > LLONG_MAX && sign == 1)
		return (-1);
	if (sum - 1 > LLONG_MAX && sign == -1)
		return (0);
	return (sum * sign);
}

int	shade_color(int color, double divide)
{
	if (divide <= 1.)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / divide) << 16)
		+ ((int)(((0x00FF00 & color) >> 8) / divide) << 8)
		+ ((int)((0x0000FF & color) / divide)));
}

int	isascii_48(int c)
{
	return (c >= 48 && c <= 125);
}
