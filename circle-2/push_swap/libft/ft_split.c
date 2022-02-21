/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:31:20 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/08 14:32:16 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_split(char const *s, char c)
{
	int	count;
	int	i;
	int	trigger;

	count = 0;
	trigger = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && trigger)
		{
			count++;
			trigger = 0;
		}
		if (s[i] == c && !trigger)
			trigger = 1;
		i++;
	}
	return (count);
}

static	int	count_char(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static	void	*free_strings(char **strings, int current)
{
	int	i;

	i = 0;
	while (i < current)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**res;
	int		current;

	if (s == NULL)
		return (NULL);
	res = malloc(sizeof(char *) * (count_split(s, c) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	current = 0;
	while (current < count_split(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		res[current] = malloc(sizeof(char) * (count_char(s + i, c) + 1));
		if (res[current] == NULL)
			return (free_strings(res, current));
		ft_strlcpy(res[current], s + i, count_char(s + i, c) + 1);
		i += count_char(s + i, c);
		current++;
	}
	res[current] = NULL;
	return (res);
}
