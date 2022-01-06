/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:31:20 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/06 18:03:05 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char **ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	int		start;
	char	**res;
	int		pos;
	
	if (s == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	if (i != 0)
		count++;
	start = i;
	while (s[i] && s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;	
	}
	res = malloc(sizeof(char *) * (count));
	if (res == NULL)
		return (NULL);
	i = start;

	while (pos < count)
	{
		j = i;
		while (s[i] && s[i] != c)
			i++;
		res[pos] = malloc(sizeof(char) * (i - j + 1));
		if (res[pos] == NULL)
			return (NULL);
		ft_strlcpy(res[pos], s + j, i - j + 1);
		while (s[i] && s[i] == c)
			i++;
		pos++;
	}
	return res;
}
