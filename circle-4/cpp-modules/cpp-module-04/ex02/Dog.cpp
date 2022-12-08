/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:01:48 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/09 00:46:09 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &src): AAnimal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	type = src.type;
	brain = new Brain(*src.brain);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog &Dog::operator=(Dog const &rhs)
{
	AAnimal::operator=(rhs);
	std::cout << "Dog copy assignment operator called" << std::endl;
	type = rhs.type;
	delete brain;
	brain = new Brain(*rhs.brain); // deep copy
	// brain = new Brain(rhs) // shalow copy
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "woof-woof" << std::endl;
}

void Dog::setIdea(int index, std::string idea)
{
	brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return brain->getIdea(index);
}