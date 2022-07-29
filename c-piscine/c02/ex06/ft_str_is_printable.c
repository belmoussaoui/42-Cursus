/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmouss <belmouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:43:13 by belmouss          #+#    #+#             */
/*   Updated: 2021/11/16 23:02:27 by belmouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (0x20 <= str[i] && str[i] <= 0x7e)
		{
			i++;
		}
		else
		{
			res = 0;
			break ;
		}
	}
	return (res);
}
