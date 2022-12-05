/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmouss <belmouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:45:07 by belmouss          #+#    #+#             */
/*   Updated: 2021/11/19 15:35:51 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	if (s1[0] == '\0' && s2[0] == '\0')
		return (0);
	if (s1[0] == '\0')
		return (-1);
	if (s2[0] == '\0')
		return (1);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}