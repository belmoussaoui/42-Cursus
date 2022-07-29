/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:55:54 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/24 21:31:57 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _raw(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	_raw = fixed.getRawBits();
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_raw = (value << Fixed::_nbits);
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_raw = roundf(value * (1 << Fixed::_nbits));
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	_raw = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return _raw;
}

void Fixed::setRawBits(int const raw) {
	_raw = raw;
}

float Fixed::toFloat() const {
	return ((float) _raw / (float) (1 << Fixed::_nbits));
}

int Fixed::toInt() const {
	return _raw >> Fixed::_nbits;
}

std::ostream& operator<<(std::ostream &out, const Fixed& fixed) {
	out << fixed.toFloat();
	return (out);
}
