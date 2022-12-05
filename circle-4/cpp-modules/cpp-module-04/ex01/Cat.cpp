/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:56:44 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/05 15:34:22 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &src): Animal(src)
{
	std::cout << "Copy constructor called" << std::endl;
	type = src.type;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs)
{
	Animal::operator=(rhs);
	std::cout << "Cat copy assignment operator called" << std::endl;
	type = rhs.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}