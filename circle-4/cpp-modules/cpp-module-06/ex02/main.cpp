/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:06:11 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/20 22:39:10 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate()
{
	int value = rand() % 3;
	if (value == 0)
		return new A();
	else if (value == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::bad_cast &e)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::bad_cast &e)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (const std::bad_cast &e)
	{
	}
}

int main()
{
	std::srand(std::time(0));
	
	std::cout << "identify type A" << std::endl;
	Base *a = new A();
	identify(a);
	identify(*a);
	delete a;
	
	std::cout << "identify type B" << std::endl;
	Base *b = new B();
	identify(b);
	identify(*b);
	delete b;
	
	std::cout << "identify type C" << std::endl;
	Base *c = new C();
	identify(c);
	identify(*c);
	delete c;
	
	std::cout << "identify type Random" << std::endl;
	Base *random = generate();
	identify(random);
	identify(*random);
	delete random;

	return 0;
}