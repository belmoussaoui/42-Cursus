/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:43:55 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/21 20:57:02 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main() {
	Point a(0, 0);
	Point b(3, 0);
	Point c(1.5, 1.5);
	std::cout << bsp(a, b, c, Point(1.5, 1.5)) << std::endl;
	std::cout << bsp(a, b, c, Point(1, 1)) << std::endl;
	std::cout << bsp(a, b, c, Point(3, 0.5)) << std::endl;
	std::cout << bsp(a, b, c, Point(1.55, 1.5)) << std::endl;
	std::cout << bsp(a, b, c, Point(0.5, 0.5)) << std::endl;
	return 0;
}
