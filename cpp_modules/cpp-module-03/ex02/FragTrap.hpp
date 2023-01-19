/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:19:55 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/01 20:17:34 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap ();
		FragTrap (const std::string& name);
   	   ~FragTrap ();
		FragTrap (const FragTrap& other);
		FragTrap&	operator=(const FragTrap& other);

		void	highFivesGuys(void);
};

#endif /* FRAGTRAP_HPP */

