/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:23:40 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/04 23:44:44 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup(const char *s)
{
	char	*dst;

	dst = x_malloc(str_len(s) + 1);
	ft_strlcpy(dst, s, str_len(s) + 1);
	return (dst);
}

char	*str_n_dup(char *src, size_t n)
{
	char	*dst;

	dst = x_malloc((min(str_len(src), n) + 1) * sizeof(char));
	str_n_cpy(dst, src, n);
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	dst_len;

	if (!s)
		return (NULL);
	if (str_len(s) < start)
		return (ft_strdup(""));
	dst_len = str_len(s + start);
	if (len < dst_len)
		dst_len = len;
	dst = x_malloc(dst_len + 1);
	ft_strlcpy(dst, s + start, dst_len + 1);
	return (dst);
}
