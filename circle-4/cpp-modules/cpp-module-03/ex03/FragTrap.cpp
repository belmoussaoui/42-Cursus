/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:32:39 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/29 21:25:48 by bel-mous         ###   ########.fr       */
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

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap ";
	std::cout << "Constructor called" << std::endl;
	_hp = 100;
	_ep = 100;
	_atk = 30;
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
	if (_hp <= 0 || _ep <= 0) {
		std::cout << "There was no effect on " << _name << "!" << std::endl;
		return ;
	}
	std::cout << _name << " request a positive hight fives!" << std::endl;
}
