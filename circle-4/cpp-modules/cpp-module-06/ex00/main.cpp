/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:41:47 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/19 17:19:02 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include <iostream>
#include <limits>
#include <iomanip>

void display_char(char c){
	std::cout << "char: ";
	if (isprint(c))
		std::cout << c << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

bool is_char(std::string litteral)
{
	return litteral.length() == 1 && !isdigit(litteral[0]);
}

void conversion_to_char(std::string litteral)
{
	char value = static_cast<char>(litteral[0]);
	display_char(value);
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << std::fixed << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << std::fixed << "double: " << static_cast<double>(value) << std::endl;
}

bool is_int(std::string litteral)
{
	for (size_t i = 0; i < litteral.length(); i++)
		if (!isdigit(litteral[i]))
			return (false);
	return (true);
}

void conversion_to_int(std::string litteral)
{
	try
	{
		int value = stoi(litteral);
		if (std::numeric_limits<char>::min() <= value && value <= std::numeric_limits<char>::max())
			display_char(static_cast<char>(value));
		else
			std::cout << "char: overflow" << std::endl;
		std::cout << "int: " << value << std::endl;
		std::cout << std::setprecision(1) << std::fixed << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << std::setprecision(1) << std::fixed << "double: " << static_cast<double>(value) << ""<< std::endl;
	}
	catch (const std::exception &err)
	{
		std::cout << "int overflow" << std::endl;
	}
}

bool is_float(std::string litteral)
{
	int dot = 0;
	for (size_t i = 0; i < litteral.length() - 1; i++)
	{
		if (!isdigit(litteral[i]) && litteral[i] != '.')
			return (false);
		if (litteral[i] == '.')
			dot += 1;
	}
	return (dot == 1) && litteral[litteral.length() - 1] == 'f';
}

void conversion_to_float(std::string litteral)
{
	try
	{
		float value = stof(litteral);
		if (std::numeric_limits<char>::min() <= value && value <= std::numeric_limits<char>::max())
			display_char(static_cast<char>(value));
		else
			std::cout << "char: overflow" << std::endl;
		if (std::numeric_limits<int>::min() <= value && value <= std::numeric_limits<int>::max())
			std::cout << "int: " << static_cast<int>(value) << std::endl;
		else
			std::cout << "int: overflow" << std::endl;
		std::cout << "float: " << value << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	}
	catch (const std::exception &err)
	{
		std::cout << "float overflow" << std::endl;
	}
}

bool is_double(std::string litteral)
{
	int dot = 0;
	for (size_t i = 0; i < litteral.length(); i++)
	{
		if (!isdigit(litteral[i]) && litteral[i] != '.')
			return (false);
		if (litteral[i] == '.')
			dot += 1;
	}
	return (dot == 1);
}

void conversion_to_double(std::string litteral)
{
	try
	{
		double value = stod(litteral);
		if (std::numeric_limits<char>::min() <= value && value <= std::numeric_limits<char>::max())
			display_char(static_cast<char>(value));
		else
			std::cout << "char: overflow" << std::endl;
		if (std::numeric_limits<int>::min() <= value && value <= std::numeric_limits<int>::max())
			std::cout << "int: " << static_cast<int>(value) << std::endl;
		else
			std::cout << "int: overflow" << std::endl;
		if (std::numeric_limits<float>::min() <= value && value <= std::numeric_limits<float>::max())
			std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		else
			std::cout << "float: overflow" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	}
	catch (const std::exception &err)
	{
		std::cout << "double overflow" << std::endl;
	}
}

bool is_double_pseudo(std::string litteral)
{
	return (litteral == "-inf" || litteral == "+inf" || litteral == "nan");
}

void conversion_to_double_pseudo(std::string litteral)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << litteral << "f" << std::endl;
	std::cout << "double: " << litteral << std::endl;
}

bool is_float_pseudo(std::string litteral)
{
	return (litteral == "-inff" || litteral == "+inff" || litteral == "nanf");
}

void conversion_to_float_pseudo(std::string litteral)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << litteral << std::endl;
	std::cout << "double: ";
	if (litteral == "-inff")
		std::cout << "-inf" << std::endl;
	if (litteral == "+inff")
		std::cout << "+inf" << std::endl;
	if (litteral == "nanf")
		std::cout << "nan" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "need one argument please" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string litteral = argv[1];
	if (is_char(litteral))
		conversion_to_char(litteral);
	else if (is_int(litteral))
		conversion_to_int(litteral);
	else if (is_float(litteral))
		conversion_to_float(litteral);
	else if (is_double(litteral))
		conversion_to_double(litteral);
	else if (is_double_pseudo(litteral))
		conversion_to_double_pseudo(litteral);
	else if (is_float_pseudo(litteral))
		conversion_to_float_pseudo(litteral);
	else
		std::cerr << "conversion impossible" << std::endl;
	return (EXIT_SUCCESS);
}