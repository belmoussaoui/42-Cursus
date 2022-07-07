/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:38:45 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/07 20:15:17 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++) {
		for (size_t j = 0; j < strlen(argv[i]); j++) {
			std::cout << (char) toupper(argv[i][j]);
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
