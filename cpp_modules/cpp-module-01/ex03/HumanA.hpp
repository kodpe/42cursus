/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:21:23 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/24 21:22:08 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string const name, Weapon const& weapon);
   	   ~HumanA (void);

		void	attack(void);

	private:
		std::string		_name;
		Weapon const&	_weapon;
};

#endif /* HUMANA_H */

