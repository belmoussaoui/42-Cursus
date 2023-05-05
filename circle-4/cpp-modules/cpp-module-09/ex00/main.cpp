/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:22:08 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/05 18:07:42 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sys/stat.h>


bool is_file(const char *path)
{
	struct stat path_stat;
	stat(path, &path_stat);
	return S_ISREG(path_stat.st_mode);
}

void check_file_argument(int argc, char *path)
{
	if (argc != 2)
	{
		std::cerr << "Program must take a file as argument." << std::endl;
		exit(EXIT_FAILURE);
	}

	std::ifstream inputFile(path);
	if (!inputFile.is_open() || !is_file(path))
	{
		std::cerr << "The argument " << path << " must be a file." << std::endl;
		exit(EXIT_FAILURE);
	}
}

bool is_valid_date_value(std::stringstream &ss, std::string date)
{
	int value;

	ss >> value;
	if (ss.fail())
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	return true;
}

bool is_valid_date(const std::string &date)
{
	struct tm tm;
	std::stringstream ss(date);

	if (!is_valid_date_value(ss, date))
		return false;
	ss.ignore(1);
	if (!is_valid_date_value(ss, date))
		return false;
	ss.ignore(1);
	if (!is_valid_date_value(ss, date))
		return false;

	if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
	{
		std::cerr << "Error: date is invalid => " << date << std::endl;
		return false;
	}
	return true;
}

bool is_valid_value(const std::string &value)
{
	std::stringstream ss(value);
	float val;
	if (ss >> val && val >= 0 && val <= 1000 && ss.eof()) {
		return true;
	}
	if (val > 1000)
		std::cerr << "Error: too large a number." << std::endl;
	else if (val < 0)
		std::cerr << "Error: not a positive number." << std::endl;
	else
		std::cerr << "Error: value is invalid => " << value << std::endl;
	return false;
}

void evaluate_line(std::string line, BitcoinExchange& bitcoin)
{
	std::stringstream ss(line);
	std::string date, value;
	if (std::getline(ss, date, '|') && std::getline(ss, value))
	{
		if (!is_valid_date(date) || !is_valid_value(value))
			;
		else
			bitcoin.evaluate(date, value);
	}
	else
		std::cerr << "Error: bad input => " << line << std::endl;
}

bool bitcoin_loop(char *path)
{
	std::ifstream file(path);
	BitcoinExchange bitcoin;

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		evaluate_line(line, bitcoin);
	}
	return true;
}

int main(int argc, char *argv[])
{
	check_file_argument(argc, argv[1]);
	bitcoin_loop(argv[1]);
	return EXIT_SUCCESS;
}
