/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:45:09 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/17 14:56:43 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon {
private:
	std::string _type;
	
public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	void setType(std::string type);
	const std::string getType();
};

#endif