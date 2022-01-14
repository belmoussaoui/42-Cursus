/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:25:12 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/14 18:16:45 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./libft/libft.h"


static int	ft_abs(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

void	ft_putnbr_fd_2(unsigned int n, int fd)
{
	unsigned int	pow;
	unsigned int	res;

	pow = 1;
	while ((n / pow) >= 10)
		pow *= 10;
	while (pow > 0)
	{
		res = n / pow;
		ft_putchar_fd(res + '0', fd);
		n -= (n / pow) * pow;
		pow /= 10;
	}
}

void	ft_puthex_fd(unsigned long n, int fd, int toupper)
{
	unsigned long	pow;
	unsigned long	res;

	pow = 1;
	while ((n / pow) >= 16)
		pow *= 16;
	while (pow > 0)
	{
		res = n / pow;
		if (res >= 10)
			if (toupper)
				ft_putchar_fd(res + 'A' - 10, fd);
			else
				ft_putchar_fd(res + 'a' - 10, fd);
		else
			ft_putchar_fd(res + '0', fd);
		n -= (n / pow) * pow;
		pow /= 16;
	}
}

int ft_printf(const char * format, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if(format[i] != '%')
            ft_putchar_fd(format[i], 1);
		else {
			i++;
			if (format[i] == 'd' || format[i] == 'i')
				ft_putnbr_fd(va_arg(ap, int), 1);
			else if (format[i] == 's')
				ft_putstr_fd(va_arg(ap, char *), 1);
			else if (format[i] == 'c')
				ft_putchar_fd((char) va_arg(ap, int), 1);
			else if (format[i] == 'u')
				ft_putnbr_fd_2(va_arg(ap, unsigned int), 1);
			else if (format[i] == 'x')
				ft_puthex_fd(va_arg(ap, int), 1, 0);
			else if (format[i] == 'X')
				ft_puthex_fd(va_arg(ap, int), 1, 1);
			else if (format[i] == 'X')
				ft_puthex_fd(va_arg(ap, int), 1, 1);
			else if (format[i] == 'p')
				ft_puthex_fd((intptr_t) va_arg(ap, void*), 1, 1);
			else
				ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (i);
}
