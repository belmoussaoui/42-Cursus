/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:26:24 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/18 11:11:25 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_integer(va_list ap)
{
	int	value;
	char *itoa;
	int len;
	
	value = va_arg(ap, int);
	ft_putnbr_fd(value, 1);
	itoa = ft_itoa(value);
	len = ft_strlen(itoa);
	free(itoa);
	return (len);
}

int	conversion_char(va_list ap)
{
	char	value;
	
	value = (char) va_arg(ap, int);
	ft_putchar_fd(value, 1);
	return (1);
}

int	conversion_hexadecimal(va_list ap, int (*f)(int), unsigned long value)
{
	unsigned long	pow;
	unsigned long	res;
	int				len;
	
	len = 0;
	pow = 1;
	while ((value / pow) >= 16)
		pow *= 16;
	while (pow > 0)
	{
		len++;
		res = value / pow;
		if (res >= 10)
				ft_putchar_fd(f(res + 'a' - 10), 1);
		else
			ft_putchar_fd(res + '0', 1);
		value -= res * pow;
		pow /= 16;
	}
	return (len);
}

int	conversion_string(va_list ap)
{
	char	*value;
	
	value = va_arg(ap, char *);
	if (!value)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(value, 1);
	return (ft_strlen(value));
}

int	conversion_unsigned(va_list ap)
{
	unsigned int	n;
	int	pow;
	int	res;
	int len;
	
	len = 0;
	n = va_arg(ap, unsigned int);
	pow = 1;
	while ((n / pow) >= 10)
		pow *= 10;
	while (pow > 0)
	{
		res = n / pow;
		ft_putchar_fd(res + '0', 1);
		n -= (n / pow) * pow;
		pow /= 10;
		len++;
	}
	return (len);
}