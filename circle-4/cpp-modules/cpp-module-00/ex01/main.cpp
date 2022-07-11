/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:35:36 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/11 19:49:48 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
	std::string command;
	PhoneBook phonebook;
	while (42) {
		std::cout << "Select your command (ADD, SEARCH or EXIT)" << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Command not found" << std::endl;
	}
	return (0);
}