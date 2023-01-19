/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:19:55 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/01 19:50:35 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap ();
		ScavTrap (const std::string& name);
   	   ~ScavTrap ();
		ScavTrap (const ScavTrap& other);
		ScavTrap&	operator=(const ScavTrap& other);

		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif /* SCAVTRAP_HPP */

