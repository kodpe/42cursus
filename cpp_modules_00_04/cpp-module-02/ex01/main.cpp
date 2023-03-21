/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:30:02 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/01 16:36:17 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

#if 0

# include <bitset>
# include <iomanip>

int main( void ) {

	Fixed const a(8388607);		// max
	Fixed const b(8388608);		// overflow
	Fixed const d(10000000); 	// overflow
	Fixed const c(-8388608); 	// min
	Fixed const e(-8388609);	// overflow
	Fixed const f(-10000000); 	// overflow
	Fixed const g(0.1f);
	Fixed const h(0.2f);
	Fixed const i(0.3f);
	Fixed const j(0.5f);
	Fixed const k(1.5f);
	Fixed const l(2.5f);
	Fixed const m(256.25f);
	Fixed const n(512.25f);

	std::bitset<32>	bits_a = a.getRawBits();
	std::bitset<32>	bits_b = b.getRawBits();
	std::bitset<32>	bits_c = c.getRawBits();
	std::bitset<32>	bits_d = d.getRawBits();
	std::bitset<32>	bits_e = e.getRawBits();
	std::bitset<32>	bits_f = f.getRawBits();
	std::bitset<32>	bits_g = g.getRawBits();
	std::bitset<32>	bits_h = h.getRawBits();
	std::bitset<32>	bits_i = i.getRawBits();
	std::bitset<32>	bits_j = j.getRawBits();
	std::bitset<32>	bits_k = k.getRawBits();
	std::bitset<32>	bits_l = l.getRawBits();
	std::bitset<32>	bits_m = m.getRawBits();
	std::bitset<32>	bits_n = n.getRawBits();

	std::cout << "                  -----------------------|--------" << std::endl;
	std::cout << "a is " << std::setw(12) << a.toInt() << " " << bits_a << std::endl;
	std::cout << "b is " << std::setw(12) << b.toInt() << " " << bits_b << std::endl;
	std::cout << "c is " << std::setw(12) << c.toInt() << " " << bits_c << std::endl;
	std::cout << "d is " << std::setw(12) << d.toInt() << " " << bits_d << std::endl;
	std::cout << "e is " << std::setw(12) << e.toInt() << " " << bits_e << std::endl;
	std::cout << "f is " << std::setw(12) << f.toInt() << " " << bits_f << std::endl;
	std::cout << "                  -----------------------|--------" << std::endl;
	std::cout << "g is " << std::setw(12) << g << " " << bits_g << std::endl;
	std::cout << "h is " << std::setw(12) << h << " " << bits_h << std::endl;
	std::cout << "i is " << std::setw(12) << i << " " << bits_i << std::endl;
	std::cout << "j is " << std::setw(12) << j << " " << bits_j << std::endl;
	std::cout << "                  -----------------------|--------" << std::endl;
	std::cout << "k is " << std::setw(12) << k << " " << bits_k << std::endl;
	std::cout << "l is " << std::setw(12) << l << " " << bits_l << std::endl;
	std::cout << "m is " << std::setw(12) << m << " " << bits_m << std::endl;
	std::cout << "n is " << std::setw(12) << n << " " << bits_n << std::endl;
	std::cout << "                  -----------------------|--------" << std::endl;

	std::cout << "sizeof(int): " << sizeof(int) << std::endl;

	return 0;
}

#else

int main( void ) {

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}

#endif
