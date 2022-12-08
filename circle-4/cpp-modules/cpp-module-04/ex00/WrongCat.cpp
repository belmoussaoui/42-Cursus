/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:01:41 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/08 21:33:00 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	type = src.type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	type = rhs.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "meow" << std::endl;
}
