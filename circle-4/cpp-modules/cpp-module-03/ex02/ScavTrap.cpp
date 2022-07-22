/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:32:39 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/22 21:03:12 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap ";
	std::cout << "Default constructor called" << std::endl;
	_name = "GLaDOS";
	_hp = 100;
	_ep = 20;
	_atk = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 20, 20) {
	std::cout << "ScavTrap ";
	std::cout << "Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name, int hp, int ep, int atk): ClapTrap(name, hp, ep, atk) {
	std::cout << "ScavTrap ";
	std::cout << "Constructor called" << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &src) {
	std::cout << "ScavTrap ";
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
	std::cout << "ScavTrap ";
	ClapTrap::attack(target);
}

void ScavTrap::guardGate() {
	std::cout << _name << " is now in Gate keeper mode!" << std::endl;
}
