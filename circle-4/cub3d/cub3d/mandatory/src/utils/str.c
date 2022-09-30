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

char	*str_r_chr(const char *s, int c)
{
	int		i;
	char	ch;

	i = str_len(s);
	ch = (char) c;
	while (i >= 0 && s[i] != ch)
		i--;
	if (i >= 0 && s[i] == ch)
		return ((char *) s + i);
	return (NULL);
}
