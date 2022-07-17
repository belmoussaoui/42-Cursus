/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:48:17 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/17 18:57:09 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
#include <stdio.h>
# include <string>
# include <iostream>



class Harl {
private:
	typedef void (Harl::*Complain)();
	Complain _complains[4];
	void debug();
	void info();
	void warning();
	void error();
	
public:
	Harl();
	void complain(std::string level);
};


#endif