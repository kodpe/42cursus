/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:31:29 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/31 21:08:29 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _nb(0) {}

Fixed::Fixed(const int value) : _nb(value << _fractional_part) {}

Fixed::Fixed(const float value) : _nb(roundf(value * (1 << _fractional_part))) {}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::~Fixed(void) {}

Fixed&	Fixed::operator=(const Fixed& other)
{
	this->_nb = other.getRawBits();
	return *this;
}

void	Fixed::setRawBits(int const raw)
{
	_nb = raw;
}

int	Fixed::getRawBits(void) const
{
	return _nb;
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
