/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmouss <belmouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:34:25 by belmouss          #+#    #+#             */
/*   Updated: 2021/11/16 23:01:50 by belmouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 1;
	while (str[i] != '\0')
	{
		if ('A' >= str[i] && str[i] <= 'Z')
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
