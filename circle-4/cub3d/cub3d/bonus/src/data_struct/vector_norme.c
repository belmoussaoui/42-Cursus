/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_norme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:19:22 by vrogiste          #+#    #+#             */
/*   Updated: 2022/09/29 17:02:42 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	vector_norme(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

double	vector_dot_product(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

t_vector	vector_normalize(t_vector v)
{
	return (vector(v.x / vector_norme(v), v.y / vector_norme(v)));
}
