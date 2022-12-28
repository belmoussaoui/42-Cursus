/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:17:05 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/23 10:40:11 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <class T>
void iter(T *array, std::size_t size, void (*f)(T &))
{
	for (size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}
}

#endif