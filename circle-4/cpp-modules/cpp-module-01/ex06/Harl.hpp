/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:48:17 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/17 20:55:56 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <stdio.h>
# include <string>
# include <iostream>

class Harl {
private:
	void debug();
	void info();
	void warning();
	void error();
	
public:
	void complain(std::string level);
};


#endif