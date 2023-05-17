/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:36:47 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/17 19:21:31 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <ctime>

class PmergeMe
{
private:
	static const int K = 5;
	std::vector<int> container1;
	std::list<int> container2;

	void checkSequence(std::vector<std::string> sequence);
	void checkIsDigit(std::string number);
	template <typename Container>
	double mergeInsertSort(Container &container);
	template <typename Container>
	void insertionSort(Container &container);
	template <typename Container>
	void mergeSort(Container &container);
	template <typename Container>
	void merge(Container &container, const Container &left, const Container &right);
	void displayResult(std::vector<std::string> sequence, double time1, double time2);
	void insertionSort1(std::vector<int>& container);
	void insertionSort2(std::list<int>& container);

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const &other);
	PmergeMe &operator=(PmergeMe const &other);
	void run(std::vector<std::string> sequence);
	static double calculateElapseTime(double startTime, double endTime);
};

#endif