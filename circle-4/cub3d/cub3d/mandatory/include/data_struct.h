/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:02:28 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/05 08:30:18 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# include "cub3d.h"

typedef struct s_dy_str
{
	char	*str;
	size_t	alloc;
	size_t	len;
}	t_dy_str;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

/* dy_str */
t_dy_str	dy_str_new(void);
void		dy_str_destroy(t_dy_str *dy_str);
void		dy_str_grow(t_dy_str *dy_str);
void		dy_str_append_c(t_dy_str *dy_str, char c);
void		dy_str_pop_back(t_dy_str *dy_str);

#endif
