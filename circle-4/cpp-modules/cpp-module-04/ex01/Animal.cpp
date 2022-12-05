/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:00:07 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/05 15:35:59 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	type = "Animal";
	brain = new Brain();
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	type = src.type;
	brain = new Brain(*src.brain);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
	delete brain;
}

Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	type = rhs.type;
	brain = new Brain(*rhs.brain);
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "no sound" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::setIdea(int index, std::string idea)
{
	brain->setIdea(index, idea);
}

std::string Animal::getIdea(int index) const
{
	return brain->getIdea(index);
}
