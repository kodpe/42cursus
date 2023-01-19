/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:21:35 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/24 21:22:16 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
	public:
		Weapon (void);
		Weapon (std::string const type);
   	   ~Weapon (void);

		std::string const&	getType(void) const;
		void				setType(std::string const type);

	private:
		std::string	_type;
};

#endif /* WEAPON_H */

