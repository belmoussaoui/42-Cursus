/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:46:58 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/28 15:25:05 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	using iterator = typename std::vector<T>::iterator;
	using const_iterator = typename std::vector<T>::const_iterator;

	iterator begin()
	{
		return std::begin(this->c);
	}

	iterator end()
	{
		return std::end(this->c);
	}

	const_iterator cbegin() const
	{
		return std::vector::cbegin(this->c);
	}

	const_iterator cend() const
	{
		return std::vector::cend(this->c);
	}
};

#endif