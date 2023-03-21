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

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int	horde_size(10);

	Zombie	*horde =zombieHorde(horde_size, "horde");

	Zombie	*zomb =zombieHorde(1, "zomb");

	for (int i = 0; i < horde_size; i++)
		horde[i].annouce();
	delete[] horde;

	zomb->annouce();
	delete[] zomb;

	return 0;
}
