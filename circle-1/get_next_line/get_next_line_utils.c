/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:55:40 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/26 20:13:06 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	size;

	if (s == NULL)
		return (0);
	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char) c;
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == ch)
			return ((char *) s);
		s++;
	}
	if (ch == '\0')
		return ((char *) s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	size_t			res;

	res = ft_strlen(src);
	if (dstsize == 0)
		return (res);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;
	size_t	res;

	dstlen = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && dstlen + i < dstsize - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (i > 0)
		dst[dstlen + i] = '\0';
	if (dstsize > dstlen)
		res = ft_strlen(src) + dstlen;
	else
		res = ft_strlen(src) + dstsize;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	res = malloc(sizeof(char) * (s1len + s2len) + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, s1len + 1);
	ft_strlcat(res, s2, s1len + s2len + 1);
	return (res);
}
