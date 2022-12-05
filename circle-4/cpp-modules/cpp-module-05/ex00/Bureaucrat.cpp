/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:39:09 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/05 23:21:40 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	name = "Alice";
	grade = 150;
}

Bureaucrat::Bureaucrat(std::string n, int g): name(n) {
	try
	{
		if (g < 1)
        	throw Bureaucrat::GradeTooHighException();
		if (g > 150)
        	throw Bureaucrat::GradeTooLowException();
		grade = g;
    }
	catch (Bureaucrat::GradeTooHighException e)
	{
		grade = 1;
        std::cout << e.what() << std::endl;
    }
	catch (Bureaucrat::GradeTooLowException e)
	{
		grade = 150;
        std::cout << e.what() << std::endl;
    }
	
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	name = src.name;
	grade = src.grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	name = rhs.name;
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
	try
	{
		if (grade <= 1)
        	throw Bureaucrat::GradeTooHighException();
		grade--;
    }
	catch (Bureaucrat::GradeTooHighException e)
	{
        std::cout << e.what() << std::endl;
    }
}

void Bureaucrat::decrement() {
	try
	{
		if (grade >= 150)
        	throw Bureaucrat::GradeTooLowException();
		grade++;
    }
	catch (Bureaucrat::GradeTooLowException e)
	{
        std::cout << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.name << ", bureaucrat grade " << b.grade << std::endl;
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}
