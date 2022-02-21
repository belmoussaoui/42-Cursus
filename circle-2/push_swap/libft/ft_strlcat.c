/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:22:18 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/11 21:07:04 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
