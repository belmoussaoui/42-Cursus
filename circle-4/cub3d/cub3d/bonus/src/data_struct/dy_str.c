/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dy_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:01:39 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/22 04:20:39 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_dy_str	dy_str_new(void)
{
	t_dy_str	dy_str;

	dy_str.alloc = 0;
	dy_str.len = 0;
	dy_str.str = x_malloc(sizeof(char));
	*dy_str.str = '\0';
	dy_str.alloc = 1;
	return (dy_str);
}

void	dy_str_destroy(t_dy_str *dy_str)
{
	free(dy_str->str);
	ft_memset(dy_str, 0, sizeof(t_dy_str));
}

void	dy_str_grow(t_dy_str *dy_str)
{
	char	*new_str;

	if (dy_str)
	{
		dy_str->alloc *= 2;
		new_str = x_malloc(dy_str->alloc * sizeof(char));
		str_n_cpy(new_str, dy_str->str, str_len(dy_str->str));
		free(dy_str->str);
		dy_str->str = new_str;
		if (!dy_str->str)
		{
			dy_str->alloc = 0;
			dy_str->len = 0;
		}
	}
}

void	dy_str_append_c(t_dy_str *dy_str, char c)
{
	if (dy_str)
	{
		if (dy_str->len == dy_str->alloc - 1)
			dy_str_grow(dy_str);
		dy_str->str[dy_str->len + 1] = '\0';
		dy_str->str[dy_str->len] = c;
		dy_str->len++;
	}
}

void	dy_str_pop_back(t_dy_str *dy_str)
{
	char	*new_str;

	if (*dy_str->str)
	{
		dy_str->str[dy_str->len - 1] = '\0';
		dy_str->len--;
		if (dy_str->alloc > 2 * dy_str->alloc + 1)
		{
			dy_str->alloc /= 2;
			new_str = x_malloc(dy_str->alloc * sizeof(char));
			str_n_cpy(new_str, dy_str->str, str_len(dy_str->str));
			free(dy_str->str);
			dy_str->str = new_str;
		}
	}
}
