/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:00:07 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/09 00:44:19 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Animal default constructor called" << std::endl;
	type = "Animal";
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	type = src.type;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	type = rhs.type;
	return *this;
}

// void AAnimal::makeSound() const
// {
// 	std::cout << "no sound" << std::endl;
// }

std::string AAnimal::getType() const
{
	return type;
}
