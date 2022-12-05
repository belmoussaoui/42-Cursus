/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:10:14 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/05 17:49:50 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "constructor :" << std::endl;
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();

	std::cout << std::endl << "destructor :" << std::endl;
	delete j; //should not create a leak
	delete i;

	std::cout << std::endl << "constructor :" << std::endl;
	const AAnimal* animals[2] = {new Dog(), new Cat()};
	
	std::cout << std::endl << "destructor :" << std::endl;
    for (int i = 0; i < 2; i++)
	{
		std::cout << std::endl;
        delete animals[i];
    }
	//system("leaks animal"); deleting line 32 in Animal.cpp should create a leak

	std::cout << std::endl << "deep copy" << std::endl;
	Dog d;
	Dog e;

	e = d;

	d.setIdea(0, "eat");
	e.setIdea(0, "sleep");
	std::cout << std::endl << d.getIdea(0) << std::endl;
	std::cout << e.getIdea(0) << std::endl;
	
	//const AAnimal *a = new AAnimal(); this line doesn't work
	return 0;
}