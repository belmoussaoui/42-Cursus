/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:30:49 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/08 17:20:32 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : Form("presidential", 25, 5), target("home")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string t): Form("presidential", 25, 5), target(t)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : target(src.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	Form::operator=(rhs);
	target = rhs.target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const 
{
	if (checkForm(executor))
	{
		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
};
