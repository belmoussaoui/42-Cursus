/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:54:56 by bel-mous          #+#    #+#             */
/*   Updated: 2022/10/03 16:10:51 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include <iostream>

int main()
{
	const Animal *meta = new Animal();
	// const Animal *j = new Dog();
	// const Animal *i = new Cat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// i->makeSound(); // will output the cat sound!
	// j->makeSound();
	meta->makeSound();
	
	return 0;
}