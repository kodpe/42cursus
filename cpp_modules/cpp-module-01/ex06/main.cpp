/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:45:38 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/29 20:12:28 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "usage : ./HarlFilter <minimum level>" << std::endl;
		return 1;
	}

	Harl	harl;

	harl.complain(av[1]);
	return 0;
}
