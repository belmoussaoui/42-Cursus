/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:41:31 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/07 16:21:38 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	pow;
	int	res;

	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	pow = 1;
	while ((n / pow) >= 10)
		pow *= 10;
	while (pow > 0)
	{
		res = (n / pow);
		ft_putchar_fd((n / pow) + '0', fd);
		n -= (n / pow) * pow;
		pow /= 10;
	}
}
