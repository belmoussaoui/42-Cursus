/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:02:31 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/15 21:48:24 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	int n = 5;
	Zombie *zombies = zombieHorde(n, "Boo");
	for (int i = 0; i < n; i++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}
