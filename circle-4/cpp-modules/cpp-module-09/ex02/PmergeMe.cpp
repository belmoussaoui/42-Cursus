/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:30:49 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/17 19:41:08 by bel-mous         ###   ########.fr       */
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

void PmergeMe::insertionSort1(std::vector<int> &container)
{
	std::vector<int>::iterator it, key;
	for (it = container.begin(); it != container.end(); ++it)
	{
		key = it;
		while (key != container.begin() && *(key - 1) > *key)
		{
			std::swap(*(key - 1), *key);
			--key;
		}
	}
}

void PmergeMe::insertionSort2(std::list<int> &container)
{
	// std::list<int>::iterator it, key;
	// for (it = container.begin(); it != container.end(); ++it) {
	//     key = it;
	//     while (key != container.begin() && *(std::prev(key)) > *key) {
	//         std::iter_swap(std::prev(key), key);
	//         --key;
	//     }
	// }
	if (container.size() <= 1)
	{
		return; // La liste est déjà triée ou vide
	}

	std::list<int>::iterator curr = std::next(container.begin()); // Commence à l'élément suivant
	std::list<int>::iterator lastSorted = container.begin();	  // Dernier élément trié

	while (curr != container.end())
	{
		int key = *curr; // Élément courant à insérer
		std::list<int>::iterator insertPos = container.begin();
		bool inserted = false;

		// Trouve la position d'insertion dans la partie triée de la liste
		while (insertPos != std::next(lastSorted) && key >= *insertPos)
		{
			++insertPos;
		}

		// Insère l'élément à sa position appropriée
		container.insert(insertPos, key);

		++curr; // Passe à l'élément suivant

		if (!inserted)
		{
			++lastSorted; // Met à jour le dernier élément trié
		}
	}
}

template <typename Container>
void PmergeMe::merge(Container &container, const Container &left, const Container &right)
{
	typename Container::const_iterator leftIt = left.begin();
	typename Container::const_iterator rightIt = right.begin();

	typename Container::iterator mergeIt = container.begin();

	while (leftIt != left.end() && rightIt != right.end())
	{
		if (*leftIt <= *rightIt)
		{
			*mergeIt = *leftIt;
			++leftIt;
		}
		else
		{
			*mergeIt = *rightIt;
			++rightIt;
		}
		++mergeIt;
	}

	while (leftIt != left.end())
	{
		*mergeIt = *leftIt;
		++leftIt;
		++mergeIt;
	}

	while (rightIt != right.end())
	{
		*mergeIt = *rightIt;
		++rightIt;
		++mergeIt;
	}
}

template <typename Container>
void PmergeMe::mergeSort(Container &container)
{
	if (container.size() <= 3000)
	{
		insertionSort(container);
		return;
	}

	// typename Container::iterator middle = container.begin();
	// std::advance(middle, container.size() / 2);

	// Container left(container.begin(), middle);
	// Container right(middle, container.end());

	// mergeSort(left);
	// mergeSort(right);

	// merge(container, left, right);
}

void PmergeMe::run(std::vector<std::string> sequence)
{
	container1.clear();
	container2.clear();
	checkSequence(sequence);

	clock_t startTime1 = clock();
	insertionSort1(container1);
	clock_t endTime1 = clock();
	double elapsedTime1 = calculateElapseTime(startTime1, endTime1);

	clock_t startTime2 = clock();
	insertionSort2(container2);
	clock_t endTime2 = clock();
	double elapsedTime2 = calculateElapseTime(startTime2, endTime2);

	displayResult(sequence, elapsedTime1, elapsedTime2);
}

double PmergeMe::calculateElapseTime(double startTime, double endTime)
{
	return static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000;
}

void PmergeMe::displayResult(std::vector<std::string> sequence, double time1, double time2)
{

	std::cout << "Before : ";
	for (size_t i = 0; i < sequence.size(); ++i)
		std::cout << sequence[i] << ' ';
	std::cout << std::endl;

	std::cout << "After : ";
	for (size_t i = 0; i < container1.size(); ++i)
		; //	std::cout << container1[i] << ' ';
	std::cout << std::endl;

	std::cout.setf(std::ios::fixed);
	std::cout.precision(5);
	std::cout << "Time to process a range of " << sequence.size() << " elements with std::vector : " << time1 << "us" << std::endl;
	std::cout << "Time to process a range of " << sequence.size() << " elements with std::list : " << time2 << "us" << std::endl;
}
