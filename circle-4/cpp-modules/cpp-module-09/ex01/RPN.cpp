/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:26:36 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/15 14:26:55 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(RPN const &other)
{
	data = other.data;
}

RPN &RPN::operator=(RPN const &other)
{
	if (this != &other)
	{
		data = other.data;
	}
	return *this;
}

bool RPN::isValidOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::handleDigit(char c, std::stringstream &ss)
{
	int a;
	
	ss.putback(c);
	ss >> a;
	data.push(a);
}

void RPN::handleOperators(char c)
{
	int a, b;

	if (data.size() < 2)
	{
		std::cout << "Error: not enough operands" << std::endl;
		exit(EXIT_FAILURE);
	}
	b = data.top();
	data.pop();
	a = data.top();
	data.pop();

	switch (c)
	{
	case '+':
		data.push(a + b);
		break;
	case '-':
		data.push(a - b);
		break;
	case '*':
		data.push(a * b);
		break;
	case '/':
		if(b == 0) {
			std::cout << "Error: division by zero" << std::endl;
			exit(EXIT_FAILURE);
		}
		data.push(a / b);
		break;
	}
}

void RPN::evaluate(std::string expression)
{
	std::stringstream ss(expression);

	char c;
	while (ss >> c)
	{
		if (isdigit(c))
			handleDigit(c, ss);
		else if (isValidOperator(c))
			handleOperators(c);
		else
		{
			std::cout << "Error: invalid character '" << c << "'" << std::endl;
			exit(EXIT_SUCCESS);
		}
	}

	if (data.size() != 1)
	{
		std::cout << "Error: too many operands" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << data.top() << std::endl;
}