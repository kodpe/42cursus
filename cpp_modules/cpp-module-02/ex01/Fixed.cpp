/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:31:29 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/01 16:39:37 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _nb(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _nb(value << _fractional_part)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _nb(roundf(value * (1 << _fractional_part)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_nb = other.getRawBits();
	return *this;
}

void	Fixed::setRawBits(int const raw)
{
	_nb = raw;
}

int	Fixed::getRawBits(void) const
{
	return (_nb);
}

int	Fixed::toInt(void) const
{
	return _nb >> _fractional_part;
}

float	Fixed::toFloat(void) const
{
	return (float)_nb / (1 << _fractional_part);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	return out << fixed.toFloat();
}
