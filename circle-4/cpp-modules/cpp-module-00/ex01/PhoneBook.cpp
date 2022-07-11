/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:52:52 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/11 19:53:30 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0), _contacts() {}

void PhoneBook::addContact() {
	_contacts[_index % 8].initialize();
	_index = (_index + 1);
}

void PhoneBook::searchContact() {
	std::string input;
	int index;

	if (_index == 0) {
		std::cout << "Nothing to display" << std::endl;
		return ;
	}
	displayContacts();
	std::cout << "Index of the entry to display" << std::endl;
	std::getline(std::cin, input);
	try {
 		index = std::stoi(input);
	} catch(std::invalid_argument& e) {
		std::cout << "Wrong index value" << std::endl;
		return ;
	} catch (const std::out_of_range & e) {
		std::cout << "Wrong index value" << std::endl;
		return ;
	}
	if (0 <= index && index < _index && index < 8)
		_contacts[index].displayLines();
	else
		std::cout << "Wrong index value" << std::endl;
}

void PhoneBook::displayContacts() {
	for (int i = 0; i < 8; i++) {
		if (i < _index)
			_contacts[i].displayTab(i);
	}
	std::cout << std::string(45, '-') << std::endl;
}