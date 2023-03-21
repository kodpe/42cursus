/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:39:06 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/24 21:22:32 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie (void);
		Zombie (std::string const name);
   	   ~Zombie (void);

		void	annouce(void);

	private:
		std::string	_name;
};

#endif /* ZOMBIE_H */

