/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:21:32 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/24 20:34:10 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(void)
{
}

Weapon::Weapon(std::string const type) :
	_type(type)
{
}

Weapon::~Weapon(void)
{
}

void	Weapon::setType(std::string const type)
{
	_type = type;
}

std::string const&	Weapon::getType(void) const
{
	return _type;
}
