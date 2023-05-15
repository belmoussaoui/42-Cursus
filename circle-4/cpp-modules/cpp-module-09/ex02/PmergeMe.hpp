/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:36:47 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/15 15:31:40 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <string>
#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
private:
	std::vector<int> container1;
	std::list<int> container2;
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const &other);
	PmergeMe& operator=(PmergeMe const &other);
	void run(std::vector<std::string> sequence);
	void checkSequence(std::vector<std::string> sequence);
	void checkIsDigit(std::string number);
};

#endif