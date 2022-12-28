/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:44:05 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/28 15:18:27 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{

private:
	unsigned int n;
	std::vector<int> numbers;

public:
	Span(unsigned int n);
	void addNumber(int x);

	template <typename InputIt>
	void addNumbers(InputIt first, InputIt last)
	{
		if (numbers.size() + std::distance(first, last) > n)
		{
			throw std::length_error("Span is full");
		}
		numbers.insert(numbers.end(), first, last);
	}
	int shortestSpan() const;
	int longestSpan() const;
};

#endif