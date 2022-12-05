/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:01:48 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/05 17:48:38 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &src): AAnimal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	type = src.type;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs)
{
	AAnimal::operator=(rhs);
	std::cout << "Dog copy assignment operator called" << std::endl;
	type = rhs.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "woof-woof" << std::endl;
}