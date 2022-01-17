/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:25:12 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/15 13:21:06 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	eval_format(const char *format, va_list ap)
{
	int	res;

	res = 0;
	if (*format == 'i' || *format == 'd')
		res += conversion_integer(ap);
	else if (*format == 'c')
		res += conversion_char(ap);
	else if (*format == 's')
		res += conversion_string(ap);
	else if (*format == 'x')
		res += conversion_hexadecimal(ap, ft_tolower);
	else if (*format == 'X')
		res += conversion_hexadecimal(ap, ft_toupper);
	else if (*format == 'p')
	{
		ft_putstr_fd("0x", 1);
		res += 2;
		res += conversion_hexadecimal(ap, ft_tolower);
	}
	else if (*format == 'u')
		res += conversion_unsigned(ap);
	else
	{
		res += 1;
		ft_putchar_fd('%', 1);
	}
	return (res);
}

int ft_printf(const char * format, ...)
{
	va_list	ap;
	int		i;
	int		res;

	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if(format[i] != '%') {
            ft_putchar_fd(format[i], 1);
			res++;
		}
		else
		{
			i++;
			res += eval_format(format + i, ap);
		}
		i++;
	}
	va_end(ap);
	return (res);
}
