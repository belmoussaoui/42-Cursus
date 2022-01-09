/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:41:31 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/07 17:58:46 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			pow;
	long int	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	pow = 1;
	while ((ln / pow) >= 10)
		pow *= 10;
	while (pow > 0)
	{
		ft_putchar_fd((ln / pow) + '0', fd);
		ln -= (ln / pow) * pow;
		pow /= 10;
	}
}
