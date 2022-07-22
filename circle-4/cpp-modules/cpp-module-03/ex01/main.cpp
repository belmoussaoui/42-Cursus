/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:15:29 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/22 16:55:24 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main() {
	ScavTrap actor("actor");
	
	actor.attack("enemy1");
	actor.attack("enemy2");
	
	actor.takeDamage(3);
	actor.takeDamage(2);
	actor.takeDamage(1);

	actor.beRepaired(3);
	actor.beRepaired(2);
	actor.beRepaired(1);

	actor.takeDamage(10);
	
	actor.attack("enemy");
	actor.takeDamage(3);
	actor.beRepaired(3);
	actor.attack("enemy");
	return 0;
}
