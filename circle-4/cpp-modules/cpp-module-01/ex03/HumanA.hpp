/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:56:56 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/17 15:27:37 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
# include <string>
# include "Weapon.hpp"
# include <iostream>

class HumanA {
private:
	std::string _name;
	Weapon &_weapon;
	
public:
	HumanA(std::string name, Weapon &weapon);
	void attack();
};

#endif