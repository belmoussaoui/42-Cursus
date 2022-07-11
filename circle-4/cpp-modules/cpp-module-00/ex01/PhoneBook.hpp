/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:27:24 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/11 18:12:11 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>

class PhoneBook {
private:
	int _index;
	Contact _contacts[8];

public:
	PhoneBook();
	void addContact();
	void searchContact();
	void displayContacts();
	void displayField();
};

#endif