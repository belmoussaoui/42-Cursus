/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:30:49 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/08 16:17:01 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

std::string const ShrubberyCreationForm::ascii =
	"       _-_\n"
	"    /~~   ~~\\\n"
	" /~~         ~~\\\n"
	"{               }\n"
	" \\  _-     -_  /\n"
	"   ~  \\\\ //  ~\n"
	"_- -   | | _- _\n"
	"  _ -  | |   -_\n"
	"      // \\\\\n";



ShrubberyCreationForm::ShrubberyCreationForm() : Form("shrubbery", 145, 137), target("home")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t): Form("shrubbery", 145, 137), target(t)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : target(src.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	Form::operator=(rhs);
	target = rhs.target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const 
{
	if (checkForm(executor))
	{
		std::ofstream of(target + "_shrubbery");
		if (of)
		{
    		of << ascii;
    		of.close();
		}
	}
};
