/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:09:07 by bel-mous          #+#    #+#             */
/*   Updated: 2022/04/15 15:31:40 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_putnbr(long long d, int i, char* base, int len)
{
	if (d <  0)
	{
		write(1, "-", 1);
		d *= -1;
		i++;
	}
	if (d < len)
	{
		int c = base[d];
		write(1, &c, 1);
		i++;
	}
	else
	{
		i = ft_putnbr(d / len, i, base, len);
		int c = base[d % len];
		i++;
		write(1, &c, 1);
	}
	return (i);
}

int ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_printf(const char *format, ...)
{
	va_list arg;
	va_start(arg, format);
	int i = 0;

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			i++;
		}
		else
		{
			format++;
			if (*format == 'd')
			{
				int d = va_arg(arg, int);
				i += ft_putnbr(d, 0, "0123456789", 10);
			}
			if (*format == 'x')
			{
				unsigned int d = va_arg(arg, unsigned int);
				i += ft_putnbr(d, 0, "0123456789abcdef", 16);
			}
			if (*format == 's')
			{
				char *d = va_arg(arg, char *);
				if (d == NULL)
					i += ft_putstr("(null)");
				else
					i += ft_putstr(d);
			}
		}
		format++;
	}
	return (i);
}
