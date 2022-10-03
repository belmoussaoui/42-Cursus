/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:00:07 by bel-mous          #+#    #+#             */
/*   Updated: 2022/10/03 16:15:26 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	type = "undefined";
}

Animal::Animal(const Animal &src)
{
	std::cout << "Copy constructor called" << std::endl;
	type = src.type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	type = rhs.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "No specific sound for this object" << std::endl;
}
