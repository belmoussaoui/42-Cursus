/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:03:06 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/17 15:34:02 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
# include <string>
# include "Weapon.hpp"
# include <iostream>


class HumanB {
private:
	std::string _name;
	Weapon *_weapon;
	
public:
	HumanB(std::string name);
	void setWeapon(Weapon &weapon);
	void attack();
};

#endif