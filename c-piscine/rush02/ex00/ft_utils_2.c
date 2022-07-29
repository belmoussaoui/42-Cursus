/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:16:05 by dcorenti          #+#    #+#             */
/*   Updated: 2021/11/28 14:38:04 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_is_suffix(char *str)
{
    if (str[0] == '1' && str[1] == '0' && str[2] == '0')
        return (1);
    else
        return (0);
}

unsigned int ft_atoi(char *str)
{
	int i;
	unsigned int res;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		i++
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res);
}

int ft_strlen_new_line(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	ft_strcpy_line(char *dest, char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}