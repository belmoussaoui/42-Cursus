/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:32:39 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/22 21:01:37 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap ";
	std::cout << "Default constructor called" << std::endl;
	_name = "GLaDOS";
	_hp = 100;
	_ep = 100;
	_atk = 30;
}

FragTrap::FragTrap(std::string name): ScavTrap(name, 100, 100, 30) {
	std::cout << "FragTrap ";
	std::cout << "Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) {
	std::cout << "Copy constructor called" << std::endl;
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_atk = src._atk;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap ";
	std::cout << "Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		_name = rhs._name;
		_hp = rhs._hp;
		_ep = rhs._ep;
		_atk = rhs._atk;
	}
	return *this;
}


void FragTrap::highFivesGuys() {
	std::cout << _name << " request a positive hight fives!" << std::endl;
}
