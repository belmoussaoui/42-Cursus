/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmouss <belmouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:15:38 by belmouss          #+#    #+#             */
/*   Updated: 2021/11/16 22:53:43 by belmouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	next;

	i = 0;
	next = 1;
	while (str[i] != '\0')
	{
		if (('A' <= str[i] && str[i] <= 'Z')
			|| ('a' <= str[i] && str[i] <= 'z'))
		{
			if (next)
			{
				str[i] -= 'a' - 'A';
				next = 0;
			}
			i++;
		}
		else
		{
			next = 1;
			i++;
		}
	}
	return (str);
}
