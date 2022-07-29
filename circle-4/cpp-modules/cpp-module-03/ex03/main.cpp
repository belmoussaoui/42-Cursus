/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:15:29 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/29 21:34:00 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main() {
	DiamondTrap actor("DiamondTrap");
	actor.attack("Jakobs");
	actor.takeDamage(3);
	actor.beRepaired(3);
	std::cout << std::endl;
	
	for (int i = 0; i < 10; i++) {
		actor.attack("Jakobs");
	}
	std::cout << std::endl;
	
	actor.takeDamage(50);
	actor.guardGate();
	actor.beRepaired(3);
	actor.highFivesGuys();
	actor.whoAmI();
	return 0;
}
