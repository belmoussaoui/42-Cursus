/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:56:44 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/09 00:37:19 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &src): Animal(src)
{
	std::cout << "Copy constructor called" << std::endl;
	type = src.type;
	brain = new Brain(*src.brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat &Cat::operator=(Cat const &rhs)
{
	Animal::operator=(rhs);
	std::cout << "Cat copy assignment operator called" << std::endl;
	type = rhs.type;
	delete brain;
	brain = new Brain(*rhs.brain);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}

void Cat::setIdea(int index, std::string idea)
{
	brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return brain->getIdea(index);
}