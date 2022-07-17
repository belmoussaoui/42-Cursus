/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:44:29 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/17 20:55:51 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

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
	int value = -1;
	for (size_t i = 0; i < 4; i++)
	{
		if (level == complainName[i])
			value = i;
	}
	switch (value) {
	case 0:
		debug();
	case 1:
		info();
	case 2:
		warning();
	case 3:
		error();
		break;
	default:
		std::cout 	<< "[ Probably complaining about "
					<< "insignificant problems ]" << std::endl;
		break;
	}
}
