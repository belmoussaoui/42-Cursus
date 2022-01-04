/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:40:16 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/04 22:13:03 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	int			i;

	d = dst;
	s = src;
	if (dst == NULL && src == NULL)
		return (dst);
	i = len - 1;
	if (dst > src)
	{
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
