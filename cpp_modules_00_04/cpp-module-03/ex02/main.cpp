/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:06:34 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/03 22:25:53 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	{
		FragTrap	a("A");
		FragTrap	acopy(a);
		a = acopy;

		a.attack("a windmill");
		a.attack("a windmill");
		a.takeDamage(1);
		a.takeDamage(1);
		a.highFivesGuys();
	}
	{
		std::cout << std::endl;

		FragTrap	b("B");
		b.attack("a windmill");
		b.takeDamage(9);
		b.beRepaired(3);
		b.takeDamage(2000);
		b.takeDamage(2000);
		b.attack("a windmill");
		b.beRepaired(3);
		b.highFivesGuys();
	}
	return 0;
}
