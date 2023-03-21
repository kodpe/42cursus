/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:02:22 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/29 17:57:45 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

#define DEBUG 0

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	std::cout << "=== PhoneBook ===" << std::endl;
	while (1)
	{
		if (std::cin.eof())
			break ;
		std::cout << "ADD / SEARCH / EXIT : ";
		if (not std::getline(std::cin, input) || input == "EXIT")
			break ;
		else if (DEBUG and input == "FILL")
			phonebook.filler();
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else
			std::cout << "unrecognized cmd '" << input << "'" << std::endl;
	}
	std::cout << std::endl << "exit" << std::endl;
	return 0;
}
