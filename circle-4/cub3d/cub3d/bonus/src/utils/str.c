/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:46:29 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/04 15:26:47 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	str_len(const char *str)
{
	if (str && *str)
		return (1 + str_len(str + 1));
	return (0);
}

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = str_len(s1);
	lens2 = str_len(s2);
	str = malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strncpy(str, s1, lens1);
	ft_strncpy(str + lens1, s2, str_len(s2));
	return (str);
}

int	str_n_cmp(const char *s1, const char *s2, size_t n)
{
	if (n > 1 && *s1 && *s1 == *s2)
		return (str_n_cmp(s1 + 1, s2 + 1, n - 1));
	return ((n > 0) * (*(unsigned char *)s1 - *(unsigned char *)s2));
}

bool	is_token(char *str, char *tokens, char sep, size_t n)
{
	char	*ptr;

	if (!tokens || !str)
		return (false);
	ptr = tokens;
	while (*ptr && *ptr != sep)
		ptr++;
	if (!str_n_cmp(str, tokens, n))
		return (true);
	if (*ptr)
		return (is_token(str, ptr + 1, sep, n));
	return (false);
}
