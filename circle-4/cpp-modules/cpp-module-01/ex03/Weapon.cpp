/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:41:45 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/17 15:21:26 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(): _type("hand") {}

Weapon::Weapon(std::string type): _type(type) {}

Weapon::~Weapon() {}

void Weapon::setType(std::string type) {
	_type = type;
}

const std::string Weapon::getType() {
	return _type;
}
