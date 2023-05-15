/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:30:49 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/15 18:52:53 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	// shallow copy
	container1 = other.container1;
	container2 = other.container2;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	if (this != &other)
	{
		container1 = other.container1;
		container2 = other.container2;
	}
	return *this;
}

void PmergeMe::checkIsDigit(std::string number)
{
	for (std::size_t i = 0; i < number.length(); i++)
	{
		char c = number[i];
		if (!std::isdigit(c))
		{
			std::cout << "Error: invalid character '" << c << "' in sequence" << std::endl;
			std::exit(EXIT_FAILURE);
		}
	}
}

void PmergeMe::checkSequence(std::vector<std::string> sequence)
{
	for (std::size_t i = 0; i < sequence.size(); i++)
	{
		try
		{

			checkIsDigit(sequence[i]);
			int num = std::stoi(sequence[i]);
			if (num > 0)
			{
				container1.push_back(num);
				container2.push_back(num);
			}
			else
			{
				std::cout << "Error: invalid number " << sequence[i] << std::endl;
				std::exit(EXIT_FAILURE);
			}
		}
		catch (const std::out_of_range &)
		{
			std::cerr << "Error: number " << sequence[i] << " is out of range" << std::endl;
			std::exit(EXIT_FAILURE);
		}
	}
}

template <typename Container>
void PmergeMe::insertionSort(Container &container)
{
	typename Container::iterator it, j;

	for (it = container.begin(); it != container.end(); ++it)
	{
		typename Container::value_type key = *it;
		j = it;
		while (j != container.begin() && *(std::prev(j)) > key)
		{
			*j = *(std::prev(j));
			--j;
		}
		*j = key;
	}
}

template <typename Container>
void PmergeMe::mergeSort(Container &container)
{
	(void)container;
}

template <typename Container>
double PmergeMe::mergeInsertSort(Container &container)
{
	clock_t startTime = clock();
	insertionSort(container);
 	clock_t endTime = clock();
	double time = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000;
	return time;
}

void PmergeMe::run(std::vector<std::string> sequence)
{
	container1.clear();
	container2.clear();
	checkSequence(sequence);
	double time1 = mergeInsertSort(container1);
	double time2 = mergeInsertSort(container2);
	displaySequence(sequence, time1, time2);
}

void PmergeMe::displaySequence(std::vector<std::string> sequence, double time1, double time2)
{
	(void) sequence;
	std::cout.setf(std::ios::fixed);
    std::cout.precision(5);
	std::cout << "Time to process a range of 3000 elements with std::[..] : " << time1 << "us" << std::endl;
	std::cout << "Time to process a range of 3000 elements with std::[..] : " << time2 << "us" << std::endl;
}