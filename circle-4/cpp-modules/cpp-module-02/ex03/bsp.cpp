/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:34:35 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/21 20:57:55 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// https://stackoverflow.com/a/2049593
float sign (Point p1, Point p2, Point p3) {
	float s1 = p1.getX().toFloat() - p3.getX().toFloat();
	float s2 = p2.getY().toFloat() - p3.getY().toFloat();
	float s3 = p2.getX().toFloat() - p3.getX().toFloat();
	float s4 = p1.getY().toFloat() - p3.getY().toFloat();
	return s1 * s2 - s3 * s4;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float d1 = sign(point, a, b);
	float d2 = sign(point, b, c);
	float d3 = sign(point, c, a);

	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}
