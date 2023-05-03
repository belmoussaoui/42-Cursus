/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:22:08 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/03 19:23:18 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>

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
		return 1;
	}
	return (true);
}

int main(int argc, char *argv[])
{
	if (check_file_argument(argc, argv[1]))
		;
	return EXIT_SUCCESS;
}
