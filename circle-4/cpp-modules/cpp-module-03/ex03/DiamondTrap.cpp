/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:35:42 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/29 21:52:57 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("GLaDOS_clap_name"), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap ";
	std::cout << "Default constructor called" << std::endl;
	_name = "GLaDOS";
	_hp = 100;
	_ep = 50;
	_atk = 30;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap ";
	std::cout << "Constructor called" << std::endl;
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hp = FragTrap::HP;
	_ep = ScavTrap::EP;
	_atk = FragTrap::ATT;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) {
	std::cout << "Copy constructor called" << std::endl;
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_atk = src._atk;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "FragTrap ";
	std::cout << "Destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		_name = rhs._name;
		_hp = rhs._hp;
		_ep = rhs._ep;
		_atk = rhs._atk;
	}
	return *this;
}

void DiamondTrap::whoAmI() {
	if (_hp <= 0 || _ep <= 0) {
		std::cout << "There was no effect on " << _name << "!" << std::endl;
		return ;
	}
	std::cout << "My name is " << _name << " and " << ClapTrap::_name << std::endl;
}
