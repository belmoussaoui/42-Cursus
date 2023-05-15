/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:26:33 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/10 19:37:31 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
private:
	std::stack<int> data;
public:
	RPN();
	RPN(std::string expression);
	~RPN();
	RPN(RPN const &other);
	RPN& operator=(RPN const &other);
	void evaluate(std::string evaluate);
	bool isValidOperator(char c);
	void handleDigit(char c, std::stringstream &ss);
	void handleOperators(char c);
};

#endif