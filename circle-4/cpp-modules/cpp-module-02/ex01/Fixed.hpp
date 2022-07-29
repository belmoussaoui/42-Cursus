/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:48:01 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/24 21:31:58 by bel-mous         ###   ########.fr       */
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
	Fixed(const Fixed& fixed);
	Fixed& operator=(const Fixed& fixed);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);

	Fixed(const int number);
	Fixed(const float number);
	float toFloat() const;
	int toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif