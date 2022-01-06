/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:07:09 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/07 00:40:01 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (s == NULL)
		return (NULL);
	res = malloc(sizeof(char) * (len + 1));
	if (start >= ft_strlen(s))
		return (res);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}
