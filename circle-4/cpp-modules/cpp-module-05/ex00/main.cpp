/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:42:37 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/13 17:24:36 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("Bob", 3);
		std::cout << b;
		b.increment();
		std::cout << b;
		b.increment();
		std::cout << b;
		b.increment();
		std::cout << b << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << std::endl;
	try
	{
		Bureaucrat c("Eve", 148);
		std::cout << c;
		c.decrement();
		std::cout << c;
		c.decrement();
		std::cout << c;
		c.decrement();
		std::cout << c;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
