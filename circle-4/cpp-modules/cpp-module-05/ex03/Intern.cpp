/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:39:09 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/13 18:49:06 by bel-mous         ###   ########.fr       */
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
			return (this->*jobs[i])(target);
	}
	throw Intern::FormNotFound();
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

const char *Intern::FormNotFound::what() const throw()
{
	return "The form name doesn't exist";
}
