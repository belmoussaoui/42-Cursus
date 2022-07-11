/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:49:33 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/11 19:15:04 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


void Contact::initialize() {
	std::cout << "First name : ";
	std::getline(std::cin, _firstName);
	
	std::cout << "Last name : ";
	std::getline(std::cin, _lastName);
	
	std::cout << "Nickname : ";
	std::getline(std::cin, _nickname);
	
	std::cout << "Phone number : ";
	std::getline(std::cin, _phoneNumber);
	
	std::cout << "Darkest secret : ";
	std::getline(std::cin, _darkestSecret);
}

void Contact::displayField(std::string field) {
	if (field.size() > 10)
		field[9] = '.';
	std::cout << "|" << std::setw(10) << field.substr(0, 10);
}

void Contact::displayLines() {
	std::cout << "First name : " << _firstName << std::endl;
	std::cout << "Last name : " << _lastName << std::endl;
	std::cout << "Nickname : " << _nickname << std::endl;
	std::cout << "Phone number : " << _phoneNumber << std::endl;
	std::cout << "Darkest secret : " << _darkestSecret << std::endl;
}

void Contact::displayTab(int index) {
	std::cout << std::string(45, '-') << std::endl;
	std::cout << "|" << std::setw(10) << index;
	displayField(_firstName);
	displayField(_lastName);
	displayField(_nickname.substr(0, 10));
	std::cout << "|" << std::endl;
}
