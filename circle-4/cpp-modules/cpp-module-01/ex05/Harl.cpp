/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:44:29 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/17 19:05:56 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	_complains[0] = &Harl::debug;
	_complains[1] = &Harl::info;
	_complains[2] = &Harl::warning;
	_complains[3] = &Harl::error;
}

void Harl::debug() {
	std::cout	<< "[ DEBUG ]" << std::endl;
	std::cout	<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-specialketchup burger. "
				<< "I really do!"
				<< std::endl;
	std::cout	<< std::endl;
}

void Harl::info() {
	std::cout	<< "[ INFO ]" << std::endl;
	std::cout	<< "I cannot believe adding extra bacon costs more money. "
				<< "You didn’t put enough bacon in my burger! "
				<< "If you did, I wouldn’t be asking for more!"
				<< std::endl;
	std::cout	<< std::endl;
}

void Harl::warning() {
	std::cout	<< "[ WARNING ]" << std::endl;
	std::cout 	<< "I think I deserve to have some extra bacon for free. "
				<< "I’ve been coming for years whereas you started "
				<< "working here since last month."
				<< std::endl;
	std::cout	<< std::endl;
}

void Harl::error() {
	std::cout	<< "[ ERROR ]" << std::endl;
	std::cout	<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
	std::cout	<< std::endl;
}

void Harl::complain(std::string level) {
	std::string complainName[] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};
	for (size_t i = 0; i < 4; i++) {
		if (level == complainName[i])
			// https://cplusplus.com/forum/beginner/239227/
			(this->*_complains[i])();
	}
}