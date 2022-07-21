/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:48:01 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/21 19:21:28 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <string>
# include <iostream>
# include <cmath>

class Fixed {
private:
	int _raw;
	static int const _nbits = 8;

public:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed& fixed);
	Fixed& operator=(const Fixed& fixed);
	~Fixed();
	
	int getRawBits() const;
	void setRawBits(int const raw);

	float toFloat() const;
	int toInt() const;

	bool operator>(const Fixed& fixed);
	bool operator<(const Fixed& fixed);
	bool operator>=(const Fixed& fixed);
	bool operator<=(const Fixed& fixed);
	bool operator==(const Fixed& fixed);
	bool operator!=(const Fixed& fixed);

	const Fixed operator+(const Fixed& fixed);
	const Fixed operator-(const Fixed& fixed);
	const Fixed operator*(const Fixed& fixed);
	const Fixed operator/(const Fixed& fixed);

	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	
	static const Fixed& min(const Fixed &f1, const Fixed &f2);
	static const Fixed& max(const Fixed&f1, const Fixed &f2);
	static Fixed&min (Fixed &f1, Fixed &f2);
	static Fixed&max (Fixed &f1, Fixed &f2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif