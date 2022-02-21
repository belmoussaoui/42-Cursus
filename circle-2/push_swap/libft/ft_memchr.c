/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:29:05 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/05 13:17:22 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;

	uc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *) s)[i] == uc)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
