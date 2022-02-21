/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:03:53 by bel-mous          #+#    #+#             */
/*   Updated: 2022/01/11 21:01:24 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = ft_strlen(s);
	ch = (char) c;
	while (i >= 0 && s[i] != ch)
		i--;
	if (i >= 0 && s[i] == ch)
		return ((char *) s + i);
	return (NULL);
}
