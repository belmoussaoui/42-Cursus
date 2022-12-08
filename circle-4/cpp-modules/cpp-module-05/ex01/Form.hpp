/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:39:18 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/07 13:47:50 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	const int grade;
	const int requiredGrade;
	bool isSigned;

public:
	Form();
	Form(std::string n, int g, int rg);
	Form(Form const &src);
	~Form();
	Form &operator=(Form const &rhs);

	std::string getName() const;
	bool getIsSigned() const;
	int getGrade() const;
	int getRequiredGrade() const;
	void beSigned(Bureaucrat b);
	
	
	friend std::ostream& operator<<(std::ostream& os, const Form& b);
	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class IsAlreadySigned : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#endif