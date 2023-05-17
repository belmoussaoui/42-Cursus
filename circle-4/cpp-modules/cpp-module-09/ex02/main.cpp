/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:22:08 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/17 18:24:18 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc <= 2)
	{
		std::cerr << "Program must take a sequence." << std::endl;
		exit(EXIT_FAILURE);
	}
	PmergeMe pmerge;
	std::vector<std::string> sequence;
	for (int i = 1; i < argc; ++i)
	{
		sequence.push_back(argv[i]);
	}
	pmerge.run(sequence);

	return EXIT_SUCCESS;
}
