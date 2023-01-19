/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:06:34 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/03 21:50:21 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	{
		ClapTrap	b("B");
		b.attack("a windmill");
		b.takeDamage(9);
		b.beRepaired(3);
		b.takeDamage(2000);
		b.takeDamage(2000);
		b.attack("a windmill");
		b.beRepaired(3);
	}
	{
		std::cout << std::endl;

		ClapTrap	a("A");
		for (int i = 0; i < 11; i++)
			a.attack("a windmill");

		std::cout << std::endl;

		for (int i = 0; i < 11; i++)
			a.takeDamage(1);
		a.beRepaired(10);
	}
	{
		std::cout << std::endl;

		ClapTrap	c("C");
		ClapTrap	d;

		for (int i = 0; i < 11; i++)
			c.beRepaired(10);
		c.takeDamage(109);

		std::cout << std::endl;

		d = c;
		d.attack("a windmill");
		d.takeDamage(1);
		d.attack("a windmill");
	}
	return 0;
}
