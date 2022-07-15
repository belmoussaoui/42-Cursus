/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:02:31 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/15 21:42:00 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie *zombie1 = newZombie("Foo");
	randomChump("Chump");
	zombie1->announce();
	delete zombie1;
	return 0;
}