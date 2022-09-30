/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:46:13 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/05 10:47:41 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!n)
		return (NULL);
	if (*((unsigned char *) s) == (unsigned char) c)
		return ((void *) s);
	return (ft_memchr(s + 1, c, n - 1));
}

char	*ft_strchr(const char *s, int c)
{
	if (*s == (char)c)
		return ((char *)s);
	if (*s)
		return (ft_strchr(s + 1, c));
	return (NULL);
}

char	*skip_spaces(char *s)
{
	if (s && ft_strchr(SPACES, *s))
		return (skip_spaces(s + 1));
	return (s);
}
