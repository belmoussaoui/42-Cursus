/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:10:55 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/20 06:20:48 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(long long int n)
{
	int count = 0;

	if (n <= 0)
		count++;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
	return (count);
}

int	ft_hexlen(unsigned long long int n)
{
	int count = 0;

	if (n == 0)
		count++;
    while (n != 0)
    {
        n = n / 16;
        count++;
    }
	return (count);
}

static int	ft_abs(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

void	ft_putlli_fd(long long int n, int fd)
{
	long long	pow;
	long long	res;

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

void	ft_puthex_fd(unsigned long long h, int (*f)(int), int fd)
{
	unsigned long	pow;
	unsigned long	res;
	
	pow = 1;
	while ((h / pow) >= 16)
		pow *= 16;
	while (pow > 0)
	{
		res = h / pow;
		if (res >= 10)
				ft_putchar_fd(f(res + 'a' - 10), fd);
		else
			ft_putchar_fd(res + '0', fd);
		h -= res * pow;
		pow /= 16;
	}
}