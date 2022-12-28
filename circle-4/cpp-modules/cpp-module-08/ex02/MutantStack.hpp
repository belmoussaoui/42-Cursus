/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:46:58 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/28 12:47:06 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return std::cbegin(this->c);
	}

	const_iterator cend() const
	{
		return std::cend(this->c);
	}
};