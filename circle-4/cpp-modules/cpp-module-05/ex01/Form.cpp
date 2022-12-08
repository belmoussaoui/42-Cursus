/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:39:09 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/07 14:13:47 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"

Form::Form(): name("A38"), grade(150), requiredGrade(150) {}

Form::Form(std::string n, int g, int rg): name(n), grade(g), requiredGrade(rg)
{
}

Form::Form(const Form &src): name(src.name), grade(src.grade),
	requiredGrade(src.requiredGrade), isSigned(src.isSigned)
{
}

Form::~Form() {}

Form &Form::operator=(Form const &rhs)
{
	isSigned = rhs.isSigned;
	return *this;
}

std::string Form::getName() const
{
	return name;
}

int Form::getGrade() const
{
	return grade;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

void Form::beSigned(Bureaucrat b) {

		if (grade < b.getGrade())
        	throw Form::GradeTooLowException();
		if (isSigned)
		{
			throw Form::IsAlreadySigned();
		}
		this->isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.name << ", form grade " << f.grade << std::endl;
    return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "The grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}

const char* Form::IsAlreadySigned::what() const throw()
{
	return "The form is already signed";
}
