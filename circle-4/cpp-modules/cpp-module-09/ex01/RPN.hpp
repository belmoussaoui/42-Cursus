/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:26:33 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/10 17:32:23 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>

class RPN
{
private:
public:
	RPN();
	~RPN();
	RPN(RPN const &other);
	RPN& operator=(RPN const &other);
};

#endif