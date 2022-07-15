/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:25:35 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/15 20:11:25 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>
# include <iomanip>

class Contact {
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:
	void initialize();
	void getField(std::string, std::string&);
	void displayLines();
	void displayField(std::string);
	void displayTab(int);
	bool isValidField(std::string);
	std::string getFirstName() { return _firstName; }
	std::string getLastName() { return _lastName; }
	std::string getNickName() { return _nickname; }
	std::string getPhoneNumber() { return _phoneNumber; }
	std::string getDarkestSecret() { return _darkestSecret; }
};

#endif