/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:59:18 by sloquet           #+#    #+#             */
/*   Updated: 2023/04/25 11:21:57 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Les vecteurs sont garantis pour stocker les éléments dans un stockage contigu,
vous pouvez donc accéder à ses éléments par index/décalage.
std::deque n'offre pas cette garantie.
*/

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	try {
		if (ac < 2 || ac > 0xf4240)
			throw std::invalid_argument("Error: nb_arg");
		PmergeMe	a(av + 1);
	}
	catch (std::invalid_argument const & e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
