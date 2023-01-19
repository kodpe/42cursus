/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:53:47 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/28 18:15:02 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool	Fixed::operator>(const Fixed& other) const
{
	return this->_nb > other.getRawBits();
}

bool	Fixed::operator<(const Fixed& other) const
{
	return this->_nb < other.getRawBits();
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return this->_nb >= other.getRawBits();
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return this->_nb <= other.getRawBits();
}

bool	Fixed::operator==(const Fixed& other) const
{
	return this->_nb == other.getRawBits();
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return this->_nb != other.getRawBits();
}
