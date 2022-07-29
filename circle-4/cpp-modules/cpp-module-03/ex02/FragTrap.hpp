/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:17:40 by bel-mous          #+#    #+#             */
/*   Updated: 2022/07/29 16:44:19 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ScavTrap.hpp"

class FragTrap: public ScavTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const &src);
	~FragTrap();
	FragTrap& operator=(FragTrap const &rhs);

	void highFivesGuys();
};

#endif