/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:43:55 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/21 19:49:32 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

void standard_test() {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
}

void personal_test() {
	Fixed a(5.05f);
	Fixed b(Fixed(5.05f) * Fixed(2));

	std::cout << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "a > b = " << (a > b) << std::endl;
	std::cout << "a >= b = " << (a >= b) << std::endl;
	std::cout << "a < b = " << (a < b) << std::endl;
	std::cout << "a <= b = " << (a <= b) << std::endl;
	std::cout << "a != b = " << (a != b) << std::endl;
	std::cout << "a == b = " << (a == b) << std::endl;
	std::cout << "a <= b = " << (a <= b) << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "b / a = " << b / a<< std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
}

int main() {
	standard_test();
	personal_test();
	return 0;
}
