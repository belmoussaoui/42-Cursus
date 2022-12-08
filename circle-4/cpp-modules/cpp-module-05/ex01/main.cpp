/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:42:37 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/07 16:11:52 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Form form("A38", 38, 38);
	Bureaucrat a("Alice", 1);
	Bureaucrat b("Bob", 68);

	b.signForm(form);
	a.signForm(form);
	a.signForm(form);

	std::cout << form;
	
	return 0;
}
