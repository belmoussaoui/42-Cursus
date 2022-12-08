/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:39:18 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/08 19:09:03 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
#define INTERN_HPP

#include <string.h>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	typedef Form* (Intern::*Job)(std::string);
	Job jobs[3];
public:
	Intern();
	Intern(Intern const &src);
	~Intern();
	Intern &operator=(Intern const &rhs);
	Form* makeForm(std::string name, std::string target);
	Form* createPresidentialPardon(std::string name);
	Form* createRobotomyRequest(std::string name);
	Form* createShrubberyCreation(std::string name);

};

#endif