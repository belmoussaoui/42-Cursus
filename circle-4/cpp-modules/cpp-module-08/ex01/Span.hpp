/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:44:05 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/29 18:46:44 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{

private:
	unsigned int N;
	std::vector<int> numbers;
	Span();

public:
	Span(unsigned int n);
	~Span();
	Span(Span const &other);
	Span &operator=(Span const &other);
	void addNumber(int x);
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan() const;
	int longestSpan() const;
};

#endif