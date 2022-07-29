/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmouss <belmouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:56:50 by belmouss          #+#    #+#             */
/*   Updated: 2021/11/16 23:37:33 by belmouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_hex(int c)
{
	if (c >= 0 && c <= 9)
		return ('0' + c);
	return (c - 10 + 'a');
}

void	ft_putstr_non_printable(char *str)
{
	int		res;
	int		i;
	char	hex;

	i = 0;
	res = 1;
	while (str[i] != '\0')
	{
		if (0x20 <= str[i] && str[i] <= 0x7e)
		{
			write(1, &str[i], 1);
		}
		else
		{
			write(1, "\\", 1);
			hex = ft_hex(str[i] / 16);
			write(1, &hex, 1);
			hex = ft_hex(str[i] % 16);
			write(1, &hex, 1);
		}
		i++;
	}
}
