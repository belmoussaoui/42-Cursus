/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:10:23 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/29 18:46:25 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "iostream"

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::~Span() {}

Span::Span(Span const &other)
{
	N = other.N;
	numbers = other.numbers;
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		N = other.N;
		numbers = other.numbers;
	}
	return *this;
}

void Span::addNumber(int x)
{
	if (numbers.size() >= N)
		throw std::length_error("Span is full");
	numbers.push_back(x);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (numbers.size() + std::distance(begin, end) > N)
		throw std::length_error("Span is full");
	numbers.insert(numbers.end(), begin, end);
}

int Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw std::length_error("Not enough numbers");
	int shortest = std::numeric_limits<int>::max();
	std::vector<int> copy = numbers;
	std::sort(copy.begin(), copy.end());
	for (unsigned int i = 0; i < copy.size() - 1; i++)
	{
		int span = std::abs(copy[i] - copy[i + 1]);
		shortest = std::min(shortest, span);
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw std::length_error("Not enough numbers");
	int min = *std::min_element(numbers.begin(), numbers.end());
	int max = *std::max_element(numbers.begin(), numbers.end());
	return max - min;
}
