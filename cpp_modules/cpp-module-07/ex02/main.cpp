/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:58:26 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/16 13:03:32 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

#define TEST(id, x)	std::cout	<< std::endl << "\033[34m" << "=== * TEST " \
								<< id << " * : " << x << " === \033[0m" << std::endl;

#define CATCH		catch (const std::exception & e) { \
						std::cout << e.what() << std::endl; }

int	main(void)
{
	TEST(1, "empty by default ")
	{
		Array<int>	a;
		try {
			std::cout << "a[0]  : " << a[0] << std::endl;
		} CATCH
		try {
			std::cout << "a[-36] : " << a[-36] << std::endl;
		} CATCH
		try {
			a[512] = 42;
		} CATCH
	}

	TEST(2, "<int> array with size 1, array[index]")
	{
		Array<int>	a(1);
		try {
			std::cout << "a[1]  : " << a[1] << std::endl;
		} CATCH
		try {
			std::cout << "a[0]  : " << a[0] << std::endl;
		} CATCH
		try {
			a[0] = 42;
			std::cout << "a[0]  : " << a[0] << std::endl;
		} CATCH
	}

	TEST(3, "copy constructor, .size()")
	{
		Array<int>	a(5);
		try {
			for (unsigned int i = 0; i < a.size(); i++)
				a[i] = i;

			std::cout << "A : ";
			for (unsigned int i = 0; i < a.size(); i++)
				std::cout << a[i] << "  ";
			std::cout << std::endl;
		} CATCH

		Array<int>	b(a);
		try {
			for (unsigned int i = 0; i < a.size(); i++)
				a[i] = i + 42;

			std::cout << "A : ";
			for (unsigned int i = 0; i < a.size(); i++)
				std::cout << a[i] << " ";
			std::cout << std::endl;
		} CATCH

		try {
			b[b.size() / 2] = 65;

			std::cout << "B : ";
			for (unsigned int i = 0; i < b.size(); i++)
				std::cout << b[i] << "  ";
			std::cout << std::endl;

			std::cout << "A : ";
			for (unsigned int i = 0; i < a.size(); i++)
				std::cout << a[i] << " ";
			std::cout << std::endl;
		} CATCH
	}

	TEST(4, "assignation, .size()")
	{
		Array<char>	a(10);
		try {
			for (unsigned int i = 0; i < a.size(); i++)
				a[i] = i;

			std::cout << "A : ";
			for (unsigned int i = 0; i < a.size(); i++)
				std::cout << a[i] << "  ";
			std::cout << std::endl;
		} CATCH

		Array<char>	b; b = a;
		try {
			for (unsigned int i = 0; i < a.size(); i++)
				a[i] = i + 42;

			std::cout << "A : ";
			for (unsigned int i = 0; i < a.size(); i++)
				std::cout << a[i] << " ";
			std::cout << std::endl;
		} CATCH

		try {
			for (unsigned int i = 0; i < b.size(); i++)
				b[i] = i + 97;

			std::cout << "B : ";
			for (unsigned int i = 0; i < b.size(); i++)
				std::cout << b[i] << "  ";
			std::cout << std::endl;

			std::cout << "A : ";
			for (unsigned int i = 0; i < a.size(); i++)
				std::cout << a[i] << " ";
			std::cout << std::endl;
		} CATCH
	}

	return 0;
}
