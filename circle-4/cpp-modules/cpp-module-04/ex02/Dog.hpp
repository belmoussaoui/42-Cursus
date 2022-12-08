/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:58:54 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/09 00:45:41 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
private:
	Brain* brain;
public:
	Dog();
	Dog(Dog const &src);
	~Dog();
	Dog &operator=(Dog const &rhs);

	void makeSound() const;
	void setIdea(int index, std::string idea);
	std::string getIdea(int index) const;
};

#endif