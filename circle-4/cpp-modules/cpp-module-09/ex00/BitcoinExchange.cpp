/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:17:19 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/10 18:03:47 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : database_name("data.csv")
{
	read_database_csv();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	data = other.data;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
	{
		data = other.data;
	}
	return *this;
}

void BitcoinExchange::read_database_csv()
{
	std::ifstream input_file(database_name.c_str());
	if (!input_file)
	{
		std::cerr << "The program failed to open the database." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string line;
	std::string date;
	double value;
	std::getline(input_file, line);
	while (std::getline(input_file, line))
	{
		std::stringstream line_stream(line);
		std::getline(line_stream, date, ',');
		line_stream >> value;
		data[date] = value;
	}
}

void BitcoinExchange::evaluate(std::string date, std::string value)
{
	std::map<std::string, double>::iterator it = data.find(date);
	double rate = 1.0;

	if (it != data.end())
		rate = it->second;
	else
	{
		it = data.lower_bound(date);
		if (it != data.begin())
		{
			--it;
			rate = it->second;
		}
		else
		{
			std::cerr << "Error: no exchange rate" << std::endl;
			return ;
		}
	}

	std::cout << date << " => " << value << " = " << rate * std::atof(value.c_str()) << std::endl;
}
