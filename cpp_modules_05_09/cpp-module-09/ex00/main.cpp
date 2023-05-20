/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:56:03 by sloquet           #+#    #+#             */
/*   Updated: 2023/04/25 11:22:06 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file.\n";
		return 1;
	}
	try {
		BitcoinExchange	a("data.csv");
		a.read_file(av[1], &BitcoinExchange::eval_line);
	}
	catch (std::invalid_argument const & e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
