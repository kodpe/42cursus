/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:02:22 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/22 03:54:19by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie	*pierre = newZombie("pierre");
	Zombie	*paul = newZombie("paul");

	pierre->annouce();
	paul->annouce();

	randomChump("jack");

	delete pierre;
	delete paul;

	randomChump("joe");
	return 0;
}
