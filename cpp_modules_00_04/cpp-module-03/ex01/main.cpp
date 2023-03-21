/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:06:34 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/03 22:14:02 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	{
		ScavTrap	a("A");
		ScavTrap	acopy(a);

		a.attack("a windmill");
		a.attack("a windmill");
		a.attack("a windmill");
		a.takeDamage(1);
		a.takeDamage(1);
		a.takeDamage(1);
		a.guardGate();
	}
	{
		std::cout << std::endl;

		ScavTrap	b("B");
		b.attack("a windmill");
		b.takeDamage(9);
		b.beRepaired(3);
		b.takeDamage(2000);
		b.takeDamage(2000);
		b.attack("a windmill");
		b.beRepaired(3);
		b.guardGate();
	}
	return 0;
}
