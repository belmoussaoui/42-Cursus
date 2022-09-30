/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:40:13 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/15 14:38:02 by vrogiste         ###   ########.fr       */
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
