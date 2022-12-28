/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:44:05 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/28 12:45:21 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Span
{

private:
	unsigned int n;
	std::vector<int> numbers;

public:
	// Construct a Span with a maximum capacity of N elements
	Span(unsigned int n) : n(n) {}

	// Add a single number to the Span
	void addNumber(int x)
	{
		if (numbers.size() == n)
		{
			throw std::length_error("Span is full");
		}
		numbers.push_back(x);
	}

	template <typename InputIt>
	void addNumbers(InputIt first, InputIt last)
	{
		if (numbers.size() + std::distance(first, last) > N_)
		{
			throw std::length_error("Span is full");
		}
		numbers.insert(numbers.end(), first, last);
	}

	int shortestSpan() const
	{
		if (numbers.size() < 2)
		{
			throw std::length_error("Not enough numbers");
		}
		int shortest = std::numeric_limits<int>::max();
		for (unsigned int i = 0; i < numbers.size() - 1; i++)
		{
			int span = std::abs(numbers_[i] - numbers_[i + 1]);
			shortest = std::min(shortest, span);
		}
		return shortest;
	}

	int longestSpan() const
	{
		if (numbers.size() < 2)
		{
			throw std::length_error("Not enough numbers");
		}
		int longest = std::numeric_limits<int>::min();
		for (unsigned int i = 0; i < numbers.size() - 1; i++)
		{
			int span = std::abs(numbers[i] - numbers_[i + 1]);
			longest = std::max(longest, span);
		}
		return longest;
	}
};
