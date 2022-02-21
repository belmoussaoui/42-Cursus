/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:40:16 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/31 14:14:34 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	int			i;

	d = (char *) dst;
	s = (const char *) src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
	{
		i = len - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
