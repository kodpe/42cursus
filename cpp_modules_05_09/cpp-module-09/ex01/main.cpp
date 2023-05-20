/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:56:03 by sloquet           #+#    #+#             */
/*   Updated: 2023/04/25 11:21:47 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error\n";
		return 1;
	}
	try {
		RPN	rpn(av[1]);
	}
	catch (std::invalid_argument const & e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
