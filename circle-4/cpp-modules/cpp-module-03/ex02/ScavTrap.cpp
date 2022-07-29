/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:32:39 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/29 21:30:00 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap ";
	std::cout << "Default constructor called" << std::endl;
	_name = "ScavTrap";
	_hp = 100;
	_ep = 50;
	_atk = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "ScavTrap ";
	std::cout << "Constructor called" << std::endl;
	_hp = 100;
	_ep = 50;
	_atk = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) {
	std::cout << "Copy constructor called" << std::endl;
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_atk = src._atk;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap ";
	std::cout << "Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << "ScavTrap ";
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		_name = rhs._name;
		_hp = rhs._hp;
		_ep = rhs._ep;
		_atk = rhs._atk;
	}
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	std::cout << "ScavTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _atk << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	if (_hp <= 0 || _ep <= 0) {
		std::cout << "There was no effect on " << _name << "!" << std::endl;
		return ;
	}
	std::cout << _name << " is now in Gate keeper mode!" << std::endl;
}
