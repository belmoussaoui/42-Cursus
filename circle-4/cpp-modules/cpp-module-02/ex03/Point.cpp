/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:08:11 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/21 20:31:26 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {};

Point::Point(const float x, const float y): _x(x), _y(y) {};

Point::Point(const Point& point) {
	_x = point.getX();
	_y = point.getY();
}

Point& Point::operator=(const Point& point) {
	_x = point.getX();
	_y = point.getY();
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
	return _x;
}

Fixed Point::getY() const {
	return _y;
}