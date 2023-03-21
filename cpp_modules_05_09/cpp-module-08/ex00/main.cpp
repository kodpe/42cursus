/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:32:09 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/17 18:07:21 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main(void)
{
	std::vector<int>	vec;

	try {
		std::cout << "vec 0  : " << *easyfind(vec, 0) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	for (int i = 0; i < 10; i++)
		vec.push_back(i + 97);

	try {
		std::cout << "vec -1 : " << *easyfind(vec, -1) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "vec 97: " << *easyfind(vec, 97) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "vec 102: " << *easyfind(vec, 102) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::list<int>		lst;

	for (int i = 0; i < 10; i++)
		lst.push_back(i + 50);

	try {
		std::cout << "lst 49 : " << *easyfind(lst, 49) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "lst 55 : " << *easyfind(lst, 55) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	lst.remove(55);

	try {
		std::cout << "lst 55 :" << *easyfind(lst, 55) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "lst 50 :" << *easyfind(lst, 50) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
