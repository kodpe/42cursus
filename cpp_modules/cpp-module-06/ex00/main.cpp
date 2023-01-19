/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:18:51 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/15 03:08:51 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Literal.hpp"

void	usage(const std::string &input)
{
		std::cout << "error: invalid input '" << input << "'" << std::endl;
		std::cout << "usage: <literal value>" << std::endl;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		usage("");
		return 1;
	}
	Literal value = Literal(av[1]);
	if (false == value.displayConv())
	{
		usage(av[1]);
		return 2;
	}
	return 0;
}
