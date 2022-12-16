/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:42:37 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/13 18:30:17 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	std::srand(std::time(0));

	try
	{
		ShrubberyCreationForm shrubbery;
		Bureaucrat b("Bob", 120);
		b.signForm(shrubbery);
		shrubbery.execute(b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		RobotomyRequestForm robotomy;
		Bureaucrat a("Alice", 44);
		a.signForm(robotomy);
		robotomy.execute(a);
		robotomy.execute(a);

		PresidentialPardonForm presidential;
		Bureaucrat e("Eve", 1);
		e.signForm(presidential);
		presidential.execute(e);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	return 0;
}
