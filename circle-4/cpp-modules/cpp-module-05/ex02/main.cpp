/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:42:37 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/08 17:18:59 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	std::srand(std::time(0));

	ShrubberyCreationForm shrubbery;
	Bureaucrat b("Bob", 120);
	b.signForm(shrubbery);
	shrubbery.execute(b);

	RobotomyRequestForm robotomy;
	b.signForm(robotomy);
	robotomy.execute(b);

	Bureaucrat a("Alice", 47);
	a.signForm(robotomy);
	robotomy.execute(a);
	a.increment();
	a.increment();
	a.increment();
	robotomy.execute(a);

	PresidentialPardonForm presidential;
	a.signForm(presidential);
	presidential.execute(a);
	Bureaucrat e("Eve", 1);
	e.signForm(presidential);
	presidential.execute(e);
	
	return 0;
}
