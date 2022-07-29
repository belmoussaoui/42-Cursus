/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:06:47 by bel-mous          #+#    #+#             */
/*   Updated: 2021/11/23 14:23:09 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_len(int n)
{
	int	len;
	int	temp;

	len = 0;
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	return (len);
}

int	ft_pow10(int n)
{
	int	res;

	res = 1;
	while (n > 0)
	{
		res *= 10;
		n--;
	}
	return (res);
}

int	is_min(int *min)
{
	if (*min == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (1);
	}
	if (*min < 0)
	{
		*min *= -1;
		ft_putchar('-');
	}
	return (0);
}

void	ft_putnbr(int nb)
{
	int	temp;
	int	len;

	if (is_min(&nb))
		return ;
	len = ft_len(nb);
	while (nb >= 10)
	{
		temp = nb;
		while (temp >= 10)
			temp /= 10;
		ft_putchar(temp + '0');
		nb -= temp * ft_pow10(ft_len(nb) - 1);
		len--;
		while (len > ft_len(nb) && len > 1)
		{
			ft_putchar('0');
			len--;
		}
	}
	ft_putchar(nb % 10 + '0');
}
