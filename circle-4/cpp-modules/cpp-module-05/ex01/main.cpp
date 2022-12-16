/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:42:37 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/13 17:56:42 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Form form("A38", 38, 38);
		Bureaucrat a("Alice", 1);
		Bureaucrat b("Bob", 100);

		a.signForm(form);
		std::cout << form;
		b.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
