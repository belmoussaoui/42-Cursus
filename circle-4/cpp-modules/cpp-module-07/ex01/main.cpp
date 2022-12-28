/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:26:51 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/23 10:45:53 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void print(char &elem)
{
	std::cout << elem << " ";
}

void ft_tolower(char &elem)
{
	elem = std::tolower(elem);
}

int main()
{
    char      array[] = {'A', 'B', 'C', 'D'};
    iter(array, 4, print);
	std::cout << std::endl;
    iter(array, 4, ft_tolower);
	iter(array, 4, print);
	std::cout << std::endl;
	return 0;
}