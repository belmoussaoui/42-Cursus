/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:00:07 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/05 17:45:23 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Animal default constructor called" << std::endl;
	type = "Animal";
	brain = new Brain();
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	type = src.type;
	brain = new Brain(*src.brain);
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
	delete brain;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	type = rhs.type;
	brain = new Brain(*rhs.brain);
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

void AAnimal::setIdea(int index, std::string idea)
{
	brain->setIdea(index, idea);
}

std::string AAnimal::getIdea(int index) const
{
	return brain->getIdea(index);
}
