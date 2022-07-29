/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:16:01 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/29 21:01:10 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap ";
	std::cout << "Default constructor called" << std::endl;
	_name = "ClapTrap";
	_hp = 10;
	_ep = 10;
	_atk = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap ";
	std::cout << "Constructor called" << std::endl;
	_name = name;
	_hp = 10;
	_ep = 10;
	_atk = 0;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << "ClapTrap ";
	std::cout << "Copy constructor called" << std::endl;
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_atk = src._atk;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap ";
	std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &rhs) {
	std::cout << "ClapTrap ";
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		_name = rhs._name;
		_hp = rhs._hp;
		_ep = rhs._ep;
		_atk = rhs._atk;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (_hp <= 0 || _ep <= 0) {
		std::cout << "There was no effect on " << target << "!" << std::endl;
		return ;
	}
	std::cout << _name << " attacks! ";
	std::cout << target << " took " << _atk << " damage!" << std::endl;
	_ep--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hp <= 0) {
		std::cout << "There was no effect on " << _name << "!" << std::endl;
		return ;
	}
	std::cout << _name << " took " << amount << " damage!" << std::endl;
	_hp -= amount;
	if (_hp <= 0) {
		std::cout << _name << " has fallen!" << std::endl;
		_hp = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hp <= 0 || _ep <= 0) {
		std::cout << "There was no effect on " << _name << "!" << std::endl;
		return ;
	}
	std::cout << _name << " recovered " << amount;
	std::cout << " hp!" << std::endl;
	_hp += amount;
	_ep--;
}
