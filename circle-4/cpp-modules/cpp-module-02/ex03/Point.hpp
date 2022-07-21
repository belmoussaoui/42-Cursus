/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:13:31 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/21 20:50:37 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point {
private:
	Fixed _x;
	Fixed _y;
public:
	Point();
	Point(const Point& point);
	Point& operator=(const Point& point);
	~Point();

	Point(const float x, const float y);
	Fixed getX() const;
	Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif