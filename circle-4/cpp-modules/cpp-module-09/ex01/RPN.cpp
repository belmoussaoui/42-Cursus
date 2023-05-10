/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:26:36 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/10 17:34:28 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "hello world" << std::endl;
}

RPN::~RPN() {}

RPN::RPN(RPN const &other)
{
	(void) other;
}

RPN &RPN::operator=(RPN const &other)
{
	if (this != &other)
	{
	}
	return *this;
}