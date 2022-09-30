/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:05:46 by vrogiste          #+#    #+#             */
/*   Updated: 2022/08/29 11:19:15 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	vector(double x, double y)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vector	vector_add(t_vector v1, t_vector v2)
{
	return (vector(v1.x + v2.x, v1.y + v2.y));
}

t_vector	vector_sub(t_vector v1, t_vector v2)
{
	return (vector(v1.x - v2.x, v1.y - v2.y));
}

t_vector	vector_scalar_multiplication(t_vector v, double a)
{
	return (vector(v.x * a, v.y * a));
}

t_vector	vector_rotate(t_vector v, double a)
{
	return (vector(v.x * cos(a) - v.y * sin(a), v.x * sin(a) + v.y * cos(a)));
}
