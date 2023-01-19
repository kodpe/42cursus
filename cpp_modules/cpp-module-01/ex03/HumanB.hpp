/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:21:27 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/24 21:22:12 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB (std::string name);
   	   ~HumanB (void);

		void	setWeapon(Weapon &weapon);
		void	attack(void);

	private:
		std::string		_name;
		Weapon*			_weapon;
};

#endif /* HUMANB_H */

