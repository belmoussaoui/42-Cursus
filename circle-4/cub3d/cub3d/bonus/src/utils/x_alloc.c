/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:40:13 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/15 13:56:42 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*x_malloc(size_t n)
{
	void	*p;

	p = malloc(n);
	if (!p)
		exit_error("can't allocate memory");
	return (p);
}

void	*x_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count && size > SIZE_MAX / count)
		return (NULL);
	ptr = x_malloc(count * size);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
