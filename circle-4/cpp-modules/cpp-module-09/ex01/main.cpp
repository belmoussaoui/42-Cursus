/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:22:08 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/15 13:48:12 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Program must take an expression." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string expression = argv[1];
	RPN rpn;
	rpn.evaluate(expression);
	
	return EXIT_SUCCESS;
}