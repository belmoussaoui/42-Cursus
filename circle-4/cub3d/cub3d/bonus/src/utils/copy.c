/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:00:37 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/30 14:12:43 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	if (n)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		ft_memcpy(dst + 1, src + 1, n - 1);
	}
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	if (len)
	{
		*(unsigned char *)b = c;
		ft_memset(b + 1, c, len - 1);
	}
	return (b);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (str_len(src));
}

void	str_n_cpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst && src)
	{
		while (src[i] && i < len)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}
