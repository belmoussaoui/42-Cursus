/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:39:09 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/08 19:17:19 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	jobs[0] = &Intern::createPresidentialPardon;
	jobs[1] = &Intern::createRobotomyRequest;
	jobs[2] = &Intern::createShrubberyCreation;
}

Intern::Intern(const Intern &src)
{
	(void) src;
}

Intern::~Intern() {
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void) rhs;
	return *this;
}

Form* Intern::makeForm(std::string name, std::string target)
{
	std::string formName[] = {
		"presidential pardon", "robotomy request", "shrubbery creation"
	};
	for (size_t i = 0; i < 4; i++) {
		if (name == formName[i])
			// https://cplusplus.com/forum/beginner/239227/
			return (this->*jobs[i])(target);
	}
	std::cout << "The form name doesn't exist" << std::endl;
	return NULL;
}

Form* Intern::createPresidentialPardon(std::string name) {
	return new PresidentialPardonForm(name);
}

Form* Intern::createRobotomyRequest(std::string name) {
	return new RobotomyRequestForm(name);
}

Form* Intern::createShrubberyCreation(std::string name) {
	return new ShrubberyCreationForm(name);
}
