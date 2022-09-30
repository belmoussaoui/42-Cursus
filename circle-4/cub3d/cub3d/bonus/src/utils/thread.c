/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:30:38 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/29 11:33:24 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_start(int i, int start, int end, int n_thread)
{
	return (i * ((end - start) / n_thread) + start);
}

int	get_end(int i, int start, int end, int n_thread)
{
	int	res;

	res = (i + 1) * ((end - start) / n_thread) + start - 1;
	if (i == n_thread - 1)
		res += end - res;
	return (res);
}
