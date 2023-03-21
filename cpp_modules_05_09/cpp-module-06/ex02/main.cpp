/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:46:34 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/13 22:45:21 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define LOG(x) std::cout << x << std::endl;

/* use dynamic_cast for polymmorphics types */

Base*	generate(void)
{
	int	i = rand() % 3;

	switch(i)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return new C();
}

void	identify(Base* p)
{
	if (p == NULL)
		return ;
	if (dynamic_cast<A*>(p) != NULL)
		LOG("A")
	if (dynamic_cast<B*>(p) != NULL)
		LOG("B")
	if (dynamic_cast<C*>(p) != NULL)
		LOG("C")
}

void	identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		LOG("A")
	}
	catch (std::exception &e) {
		// std::cout << e.what() << std::endl;
	}

	try {
		(void)dynamic_cast<B&>(p);
		LOG("B")
	}
	catch (std::exception &e) {
		// std::cout << e.what() << std::endl;
	}

	try {
		(void)dynamic_cast<C&>(p);
		LOG("C")
	}
	catch (std::exception &e) {
		// std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	srand(time(NULL));

	LOG("TEST 1")
	Base*	ptr;
	for (int i = 0; i < 10; i++)
	{
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
		std::cout << "--" << std::endl;
	}

	LOG("TEST 2")
	Base	test;
	identify(test);

	LOG("TEST 3")
	identify(NULL);

	return 0;
}
