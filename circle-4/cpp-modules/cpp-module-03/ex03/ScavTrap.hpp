/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:17:40 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/29 21:54:06 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap();
	ScavTrap& operator=(ScavTrap const &rhs);

	void attack(std::string const &target);
	void guardGate();
	static const int HP = 100;
	static const int EP = 50;
	static const int ATT = 20;
};

#endif