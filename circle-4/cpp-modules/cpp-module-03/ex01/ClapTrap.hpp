/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:17:40 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/29 16:07:36 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
protected:
	std::string _name;
	int _hp;
	int _ep;
	int _atk;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap();
	ClapTrap& operator=(ClapTrap const &rhs);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif