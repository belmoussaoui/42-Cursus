/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:24:48 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/06 14:01:41 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needlelen;

	i = 0;
	needlelen = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *) haystack);
	while (haystack[i] != '\0' && i + needlelen <= len)
	{
		if (ft_strncmp(&(haystack[i]), needle, needlelen) == 0)
			return ((char *) haystack + i);
		i++;
	}
	return (0);
}
