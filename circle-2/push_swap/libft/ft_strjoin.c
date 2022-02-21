/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:56:12 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/07 00:39:32 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
