/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:42:37 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/08 19:20:45 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	Intern intern;
	std::cout << intern.makeForm("robotomy request", "Bender")->getGrade() << std::endl;
	std::cout << intern.makeForm("presidential pardon", "Bender")->getGrade() << std::endl;
	std::cout << intern.makeForm("shrubbery creation", "Bender")->getGrade() << std::endl;
	std::cout << intern.makeForm("shrubbery2 creation", "Bender") << std::endl;
	
	return 0;
}
