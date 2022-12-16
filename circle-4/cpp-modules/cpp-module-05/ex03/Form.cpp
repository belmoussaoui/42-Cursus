/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:39:09 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/13 18:13:09 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"

Form::Form(): name("A38"), grade(150), requiredGrade(150), isSigned(false) {}

Form::Form(std::string n, int g, int rg): name(n), grade(g), requiredGrade(rg), isSigned(false)
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
		throw Form::IsAlreadySigned();
	this->isSigned = true;
}

void Form::display(std::ostream &os) const
{
    os << name << ", form grade " << grade << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	f.display(os);
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

const char* Form::IsNotSigned::what() const throw()
{
	return "The form isn't signed";
}

void Form::checkForm(Bureaucrat const &executor) const {
	if (requiredGrade < executor.getGrade())
		throw Form::GradeTooLowException();
	if (!isSigned)
		throw Form::IsNotSigned();
}
