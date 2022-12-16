/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:39:09 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/13 17:58:28 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Alice")
{
	grade = 150;
}

Bureaucrat::Bureaucrat(std::string n, int g) : name(n)
{
	if (g < 1)
		throw Bureaucrat::GradeTooHighException();
	if (g > 150)
		throw Bureaucrat::GradeTooLowException();
	grade = g;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name)
{
	grade = src.grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	grade = rhs.grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::increment()
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrement()
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

void Bureaucrat::display(std::ostream &os) const
{
	os << name << ", bureaucrat grade " << grade << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	b.display(os);
	return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}



void Bureaucrat::signForm(Form &form)
{

	form.beSigned(*this);
	std::cout << name << " signed " << form.getName() << std::endl;
}