/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:55:10 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/20 21:30:09 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "data.hpp"

uintptr_t serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int	main( void )
{
	Data		*data1 = new Data;
	Data		*data2;
	uintptr_t	raw;

	data1->data = "Hello World!";
	raw = serialize(data1);
	std::cout << "reinterpratation :" << data1 << " => " << raw << std::endl;
	data2 = deserialize(raw);
	
	std::cout << "deserialize :" << data1 << " == " << data2 << std::endl;
	std::cout << data1->data << " == " << data2->data << std::endl;
}