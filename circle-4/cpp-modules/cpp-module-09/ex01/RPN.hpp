/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:26:33 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/18 18:55:10 by bel-mous         ###   ########.fr       */
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
	bool isValidOperator(char c);
	void handleDigit(char c, std::stringstream &ss);
	void handleOperators(char c);
public:
	RPN();
	~RPN();
	RPN(RPN const &other);
	RPN& operator=(RPN const &other);
	void evaluate(std::string evaluate);
};

#endif