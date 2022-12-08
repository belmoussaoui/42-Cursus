/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:54:56 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/08 22:12:27 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	std::cout << "Create Animal (meta) :" << std::endl;
	const Animal *meta = new Animal();
	
	std::cout << std::endl << "Create Dog (j) :" << std::endl;
	const Animal *j = new Dog();
	
	std::cout << std::endl << "Create Cat (i) :" << std::endl;
	const Animal *i = new Cat();
	
	std::cout << std::endl;
	std::cout << "j->getType() = " << j->getType() << " " << std::endl;
	std::cout << "i->getType() = " << i->getType() << " " << std::endl;

	std::cout << std::endl;
	std::cout << "j->makeSound() = "; j->makeSound();
	std::cout << "i->makeSound() = "; i->makeSound();
	std::cout << "meta->makeSound() = "; meta->makeSound();

	std::cout << std::endl;
	std::cout << "Delete Animal (meta) :" << std::endl;
	delete meta;

	std::cout << std::endl << "Delete Dog (j) :" << std::endl;
	delete j;

	std::cout << std::endl << "Delete Cat (i) :" << std::endl;
	delete i;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl << "Create WrongAnimal (wrong_meta) :" << std::endl;
	const WrongAnimal *wrong_meta = new WrongAnimal();
	
	std::cout << std::endl << "Create WrongCat (wrong_i) :" << std::endl;
	// runtime polymorphism with virtual keyword in destructor missing in base class
	const WrongAnimal *wrong_i = new WrongCat();
	
	std::cout << std::endl;
	std::cout << "wrong_i->getType() = " << wrong_i->getType() << " " << std::endl;

	std::cout << std::endl;
	std::cout << "wrong_i->makeSound() = "; wrong_i->makeSound();
	std::cout << "wrong_meta->makeSound() = "; wrong_meta->makeSound();

	std::cout << std::endl;
	std::cout << "Delete WrongAnimal (wrong_meta) :" << std::endl;
	delete wrong_meta;

	std::cout << std::endl << "Delete WrongCat (wrong_i) :" << std::endl;
	delete wrong_i;

	std::cout << std::endl << "Create WrongCat (wrong_cat) without polymorphism :" << std::endl;
	const WrongCat wrong_cat;

	std::cout << std::endl;
	std::cout << "wrong_cat->makeSound() = "; wrong_cat.makeSound();
	
	return 0;
}