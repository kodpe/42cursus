/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:45:54 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/13 21:12:45 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

/*
	reinterpret cast
	pour convertir des pointeurs vers des typpes de structures de données

	uintptr_t
	utile pour faire de l'arithmetique d'adresse,
	des operations mathematiques avec des pointeurs,
	on utilise alors uintptr_t a la place de void*
*/

int	main(void)
{
	Data		data = {.c = 42, .c2 = 98, .i = 97, .d = 122, .s = "test"};

	std::cout << "sizeof(Data)          : '" << sizeof(Data) << "'" << std::endl;
	std::cout << "sizeof(char)          : '" << sizeof(char) << "'" << std::endl;
	std::cout << "sizeof(int)           : '" << sizeof(int) << "'" << std::endl;
	std::cout << "sizeof(double)        : '" << sizeof(double) << "'" << std::endl;
	std::cout << "sizeof(std::string)   : '" << sizeof(std::string) << "'" << std::endl;

	std::cout << std::endl;

	uintptr_t	raw = serialize(&data);

	Data*		dataptr = deserialize(raw);

	std::cout << "Data		data     hex: '" << &data << "'" << std::endl;
	std::cout << "uintptr_t	raw      dec: '" << raw << "'" << std::endl;
	std::cout << "Data*		dataptr  hex: '" << dataptr << "'" << std::endl;


	std::cout << std::endl;

	std::cout << "Data*		data.c      : '" << data.c << "'" << std::endl;
	std::cout << "Data*		data.c2     : '" << data.c2 << "'" << std::endl;
	std::cout << "Data*		data.i      : '" << data.i << "'" << std::endl;
	std::cout << "Data*		data.d      : '" << data.d << "'" << std::endl;
	std::cout << "Data*		data.s      : '" << data.s << "'" << std::endl;

	std::cout << std::endl;

	std::cout << "Data*		dataptr->c  : '" << dataptr->c << "'" << std::endl;
	std::cout << "Data*		dataptr->c2 : '" << dataptr->c2 << "'" << std::endl;
	std::cout << "Data*		dataptr->i  : '" << dataptr->i << "'" << std::endl;
	std::cout << "Data*		dataptr->d  : '" << dataptr->d << "'" << std::endl;
	std::cout << "Data*		dataptr->s  : '" << dataptr->s << "'" << std::endl;

	std::cout << std::endl;

	raw += 4;
	// raw += 1;
	// raw += 32;
	// raw += 33;
	Data*		dataptr2 = deserialize(raw);
	std::cout << "Data		data     hex: '" << &data << "'" << std::endl;
	std::cout << "uintptr_t	raw      dec: '" << raw << "'" << std::endl;
	std::cout << "Data*		dataptr2 hex: '" << dataptr2 << "'" << std::endl;

	std::cout << std::endl;

	std::cout << "Data*		dataptr2->c : '" << dataptr2->c << "'" << std::endl;
	// std::cout << "Data*		dataptr2->i : '" << dataptr2->i << "'" << std::endl;
	// std::cout << "Data*		dataptr2->d : '" << dataptr2->d << "'" << std::endl;
	// std::cout << "Data*		dataptr2->s : '" << dataptr2->s << "'" << std::endl;

	return 0;
}
