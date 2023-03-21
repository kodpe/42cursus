/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:26:17 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/01 16:26:18 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#if 1

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

#else
int main(void)
{
	Fixed a;
	std::cout << "a : " << a << std::endl;

	const Fixed b(12);
	std::cout << "b : " << b << std::endl;

	const Fixed c(42.25f);
	std::cout << "c : " << c << std::endl;

	Fixed d(c);
	std::cout << "d : " << d << std::endl;

	a = b;
	std::cout << "a : " << a << std::endl << std::endl;

	Fixed z(0);
	std::cout << "a / z is " << (a / z) << std::endl;
	std::cout << std::endl;

	std::cout << "comparisons" << std::endl;
	std::cout << "a < c is " << (a < c) << std::endl;
	std::cout << "a < b is " << (a < b) << std::endl;
	std::cout << "a > c is " << (a > c) << std::endl;
	std::cout << "a > b is " << (a > b) << std::endl;
	std::cout << "a <= c is " << (a <= c) << std::endl;
	std::cout << "a <= b is " << (a <= b) << std::endl;
	std::cout << "a >= c is " << (a >= c) << std::endl;
	std::cout << "a >= b is " << (a >= b) << std::endl;
	std::cout << "a == c is " << (a == c) << std::endl;
	std::cout << "a == b is " << (a == b) << std::endl;
	std::cout << "a != c is " << (a != c) << std::endl;
	std::cout << "a != b is " << (a != b) << std::endl << std::endl;

	std::cout << "arithmetic" << std::endl;
	std::cout << "c + a = " << (c + a) << std::endl;
	std::cout << "c - a = " << (c - a) << std::endl;
	std::cout << "c * a = " << (c * a) << std::endl;
	std::cout << "c / a = " << (c / a) << std::endl << std::endl;

	std::cout << "increment / decrement" << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a is: " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a is: " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a is: " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a is: " << a << std::endl << std::endl;

	std::cout << "min / max" << std::endl;
	std::cout << "min(a, d) = " << Fixed::min(a, d) << std::endl;
	std::cout << "min(b, c) = " << Fixed::min(b, c) << std::endl;
	std::cout << "max(a, d) = " << Fixed::max(a, d) << std::endl;
	std::cout << "max(b, c) = " << Fixed::max(b, c) << std::endl << std::endl;

	return 0;
}

#endif
