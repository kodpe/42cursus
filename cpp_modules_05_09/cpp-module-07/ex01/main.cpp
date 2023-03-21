/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:04:39 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/16 12:55:48 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

#if 1
template <typename T>
void	show(const T& n) {
	std::cout << n << " ";
}

template< typename T >
void	up(const T & nb) {
	std::cout << static_cast<T>(nb + 1) << " ";
}

int	main(void)
{
	{
		int tab[] 	= {97, 98, 99, 100, 42};
		size_t n 	= sizeof(tab) / sizeof(tab[0]);

		::iter(tab, n, &show);
		std::cout << std::endl;

		::iter(tab, n, &up);
		std::cout << std::endl;
	}
	{
		char tab[] 	= "abcd*";
		size_t n 	= sizeof(tab) / sizeof(tab[0]);

		::iter(tab, n, &show);
		std::cout << std::endl;

		::iter(tab, n, &up);
		std::cout << std::endl;
	}
	return 0;
}
#endif
