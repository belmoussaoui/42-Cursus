/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:21:56 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/04 23:45:06 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*start(char *s, char c)
{
	if (!*s || *s != c)
		return (s);
	return (start(s + 1, c));
}

static char	*end(char *s, char c)
{
	if (!*s)
		return (s);
	if (*s == c)
		return (end(s + 1, c));
	while (*s && *s != c)
		s++;
	return (s);
}

static size_t	count_words(char *s, char c)
{
	if (*start(s, c))
		return (1 + count_words(end(s, c), c));
	return (0);
}

char	**ft_split(char const *str, char c)
{
	char	**dst;
	char	**ptr;
	char	*s;

	s = (char *)str;
	dst = x_malloc(sizeof(char *) * (1 + count_words(s, c)));
	ptr = dst;
	while (*start(s, c))
	{
		*ptr = ft_substr(start(s, c), 0, end(s, c) - start(s, c));
		ptr++;
		s = end(s, c);
	}
	*ptr = NULL;
	return (dst);
}
