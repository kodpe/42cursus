/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_increment_decrement.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:58:53 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/31 21:01:59 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// prefix increment
Fixed&	Fixed::operator++()
{
	++_nb;
	return *this;
}

// postfix increment
Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++*this;
	return (tmp);
}

// prefix decrement
Fixed&	Fixed::operator--()
{
	--_nb;
	return *this;
}

// postfix decrement
Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--*this;
	return (tmp);
}

