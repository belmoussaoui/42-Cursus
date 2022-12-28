/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:10:23 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/28 15:19:18 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : n(n) {}

void Span::addNumber(int x)
{
	if (numbers.size() == n)
	{
		throw std::length_error("Span is full");
	}
	numbers.push_back(x);
}

int Span::shortestSpan() const
{
	if (numbers.size() < 2)
	{
		throw std::length_error("Not enough numbers");
	}
	int shortest = std::numeric_limits<int>::max();
	for (unsigned int i = 0; i < numbers.size() - 1; i++)
	{
		int span = std::abs(numbers[i] - numbers[i + 1]);
		shortest = std::min(shortest, span);
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (numbers.size() < 2)
	{
		throw std::length_error("Not enough numbers");
	}
	int longest = std::numeric_limits<int>::min();
	for (unsigned int i = 0; i < numbers.size() - 1; i++)
	{
		int span = std::abs(numbers[i] - numbers[i + 1]);
		longest = std::max(longest, span);
	}
	return longest;
}
