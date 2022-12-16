/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:42:37 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/13 18:56:24 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	Intern intern;
	try
	{
		Form *form = intern.makeForm("robotomy request", "target");
		std::cout << *form;
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form *form = intern.makeForm("shrubbery creation", "target");
		std::cout << *form;
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form *form = intern.makeForm("presidential pardon", "target");
		std::cout << *form;
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form *form = intern.makeForm("telegram request", "target");
		std::cout << *form;
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	
	return 0;
}
