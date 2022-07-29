/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:15:29 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/29 21:10:31 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {
	ClapTrap actor("ClapTrap");
	actor.attack("Jakobs");
	actor.takeDamage(3);
	actor.beRepaired(3);
	std::cout << std::endl;
	
	for (int i = 0; i < 10; i++) {
		actor.attack("Jakobs");
	}
	std::cout << std::endl;
	
	actor.takeDamage(10);
	actor.beRepaired(3);
	return 0;
}
