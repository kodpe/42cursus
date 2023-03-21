/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:26:11 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/17 22:51:58by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>

#if 1
int	main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}

#else

int	gen_random(void) { return std::rand() % 100; }

int	main()
{
	std::srand(unsigned(std::time(NULL)));

	std::cout << "=== EXCEPTIONS TEST ===" << std::endl;
	{
		Span sp;

		try {
			sp.addNumber(42);
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}

		try {
			std::cout << "shortest : " << sp.shortestSpan() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}

		try {
			std::cout << "longest  : " << sp.longestSpan() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}


		std::cout << std::endl;
	}

	std::cout << "=== BASIC TEST : addNumber() ===" << std::endl;
	{
		Span sp = Span(9);
		try {
			sp.addNumber(-100);
			sp.addNumber(0);
			sp.addNumber(-50);
			sp.addNumber(1);
			sp.displaySpan();
			std::cout << "shortest : " << sp.shortestSpan() << std::endl;
			std::cout << "longest  : " << sp.longestSpan() << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "=== BASIC TEST : addRange() ===" << std::endl;
	{
		Span 				sp(22);
		std::vector<int>	tmp(20);
		try {
			sp.addNumber(42);
			std::generate(tmp.begin(), tmp.end(), &gen_random);
			sp.addRange(tmp.begin(), tmp.end());
			sp.displaySpan();
			sp.addNumber(42);
			sp.displaySpan();
			sp.addRange(tmp.begin(), tmp.end());
			sp.displaySpan();
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "=== COPY TEST : ===" << std::endl;
	{
		Span sp = Span(9);
		try {
			sp.addNumber(-100);
			sp.addNumber(0);
			sp.addNumber(-50);
			sp.addNumber(1);
			std::cout << "sp  : "; sp.displaySpan();

			Span copy(sp);
			std::cout << "copy: "; copy.displaySpan();

			sp.addNumber(42);
			copy.addNumber(9000);

			std::cout << "sp  : "; sp.displaySpan();
			std::cout << "copy: "; copy.displaySpan();
			std::cout << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "=== SMALL TEST : fill() ===" << std::endl;
	{
		try {
			Span sp = Span(6);
			sp.fill();
			sp.displaySpan();
			std::cout << "shortest : " << sp.shortestSpan() << std::endl;
			std::cout << "longest  : " << sp.longestSpan() << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;

	std::cout << "=== BIG TEST   : fill() ===" << std::endl;
	{
		try {
			Span sp = Span(100000);
			sp.fill();
			std::cout << "shortest : " << sp.shortestSpan() << std::endl;
			std::cout << "longest  : " << sp.longestSpan() << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}

#endif
