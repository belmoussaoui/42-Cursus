/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:06:56 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/05 14:14:21 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
protected:
	std::string ideas[100];

public:
	Brain();
	Brain(Brain const &src);
	~Brain();
	Brain &operator=(Brain const &rhs);

	void setIdea(int index, std::string idea);
	std::string getIdea(int index) const;
};

#endif