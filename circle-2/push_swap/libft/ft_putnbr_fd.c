/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:41:31 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/11 20:40:09 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	pow;
	int	res;

	if (n < 0)
		ft_putchar_fd('-', fd);
	pow = 1;
	while ((n / pow) >= 10 || (n / pow) <= -10)
		pow *= 10;
	while (pow > 0)
	{
		res = ft_abs(n / pow);
		ft_putchar_fd(res + '0', fd);
		n -= (n / pow) * pow;
		pow /= 10;
	}
}
