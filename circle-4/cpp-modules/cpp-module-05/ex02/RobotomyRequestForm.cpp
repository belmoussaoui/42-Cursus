/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:30:49 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/13 18:17:43 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : Form("robotomy", 72, 45), target("home")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string t): Form("robotomy", 72, 45), target(t)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : target(src.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	Form::operator=(rhs);
	target = rhs.target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const 
{
	checkForm(executor);
	if ((rand() & 1))
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << target << " has been failed to robotomized" << std::endl;
};
