/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:22:08 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/03 20:21:45 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <sstream>

bool is_file(const char *path)
{
	struct stat path_stat;
	stat(path, &path_stat);
	return S_ISREG(path_stat.st_mode);
}

bool check_file_argument(int argc, char *path)
{
	if (argc != 2)
	{
		std::cout << "Program must take a file as argument." << std::endl;
		return false;
	}

	std::ifstream inputFile(path);
	if (!inputFile.is_open() || !is_file(path))
	{
		std::cout << "The argument " << path << " must be a file." << std::endl;
		return true;
	}
	return true;
}

bool is_valid_date(const std::string &date)
{
	// Vérifie que la date est au format "Year-Month-Day"
	int year, month, day;
	std::stringstream ss(date);

	ss >> year;
	if (ss.fail())
	{
		std::cerr << "Failed to extract year from date string" << std::endl;
		return false;
	}
	ss.ignore(1); // Ignore the first separator
	ss >> month;
	if (ss.fail())
	{
		std::cerr << "Failed to extract month from date string" << std::endl;
		return false;
	}
	ss.ignore(1); // Ignore the second separator
	ss >> day;
	if (ss.fail())
	{
		std::cerr << "Failed to extract day from date string" << std::endl;
		return false;
	}
	return true;
}

bool is_valid_value(const std::string &value)
{
	// Vérifie que la valeur est comprise entre 0 et 1000
	std::stringstream ss(value);
	float val;
	if (ss >> val && val >= 0 && val <= 1000 && ss.eof())
	{
		return true;
	}
	return false;
}

bool check_input_file(char *path)
{
	std::ifstream file(path);

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date, value;
		if (std::getline(ss, date, '|') && std::getline(ss, value))
		{
			if (!is_valid_date(date) || !is_valid_value(value))
			{
				std::cerr << "valid_date = " << is_valid_date(date) << " valid_value = " << is_valid_value(value) << std::endl;
				std::cerr << "Invalid format: " << line << "\n";
			}
			else
			{
				std::cerr << "Valid format: " << line << "\n";
			}
		}
		else
		{
			std::cerr << "Invalid format: " << line << "\n";
		}
		std::cerr << "\n";
	}
	return true;
}

int main(int argc, char *argv[])
{
	if (check_file_argument(argc, argv[1]))
	{
		check_input_file(argv[1]);
	}
	return EXIT_SUCCESS;
}
