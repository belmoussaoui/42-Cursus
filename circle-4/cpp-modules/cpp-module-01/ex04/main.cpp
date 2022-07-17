/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:53:30 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/17 16:39:50 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int replace(std::string filename, std::string s1, std::string s2)
{
	std::string line;
	std::ifstream infile(filename);
	if (!infile || s1.empty())
		return 1;
	std::ofstream outfile(filename + ".replace");
	if (!outfile)
		return 1;
	while (std::getline(infile, line)) {
		size_t pos = 0;
		while (true) {
			pos = line.find(s1, pos);
			if (pos == std::string::npos)
				break ;
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}

int main(int argc, char** argv) {
	if (argc != 4)
		return 1;
	return replace(argv[1], argv[2], argv[3]);
}