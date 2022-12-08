/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:56:58 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/09 00:45:46 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
{
private:
	Brain* brain;
public:
	Cat();
	Cat(Cat const &src);
	~Cat();
	Cat &operator=(Cat const &rhs);

	void makeSound() const;
	void setIdea(int index, std::string idea);
	std::string getIdea(int index) const;
};

#endif