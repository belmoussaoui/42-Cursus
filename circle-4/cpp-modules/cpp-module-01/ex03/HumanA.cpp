/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:04:37 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/17 15:28:56 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):
	_name(name), _weapon(weapon) {}

void HumanA::attack() {
	std::cout << _name << " attacks with their ";
	std::cout << _weapon.getType() << std::endl;
}
