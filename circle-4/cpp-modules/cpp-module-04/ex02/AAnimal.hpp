/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:17:40 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/05 17:45:01 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class AAnimal
{
protected:
	std::string type;
	Brain* brain;

public:
	AAnimal();
	AAnimal(AAnimal const &src);
	virtual ~AAnimal();
	AAnimal &operator=(AAnimal const &rhs);

	virtual void makeSound() const = 0;
	std::string getType() const;
	void setIdea(int index, std::string idea);
	std::string getIdea(int index) const;
};

#endif