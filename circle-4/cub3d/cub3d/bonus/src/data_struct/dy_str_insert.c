/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dy_str_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 04:19:57 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/22 04:22:08 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dy_str_append_str(t_dy_str *dy_str, char *s)
{
	if (s && *s)
	{
		dy_str_append_c(dy_str, *s);
		dy_str_append_str(dy_str, s + 1);
	}
}
