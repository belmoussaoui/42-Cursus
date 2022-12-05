/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:42:37 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/05 23:24:13 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("Bob", 3);
	std::cout << b;
	b.increment();
	std::cout << b;
	b.increment();
	std::cout << b;
	b.increment();
	std::cout << b << std::endl;


	Bureaucrat c("Eve", 148);
	c.decrement();
	std::cout << c;
	c.decrement();
	std::cout << c;
	c.decrement();
	std::cout << c;
	return 0;
}
