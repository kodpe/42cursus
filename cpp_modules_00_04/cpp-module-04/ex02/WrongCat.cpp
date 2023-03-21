/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:47:00 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/08 15:34:40 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#define CLASSNAME "WrongCat"
#define ANIMAL_SOUND "miaou"

WrongCat::WrongCat() : WrongAnimal()
{
	LOG_DEFAULT_CONSTRUCTOR(CLASSNAME)
	type = CLASSNAME;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
	LOG_COPY_CONSTRUCTOR(CLASSNAME)
	*this = other;
}

WrongCat::~WrongCat()
{
	LOG_DESTRUCTOR(CLASSNAME)
}

WrongCat&	WrongCat::operator=(const WrongCat &other)
{
	LOG_OPERATOR_ASSIGN(CLASSNAME)
	this->type = other.type;
	return *this;
}

void	WrongCat::makeSound(void) const
{
	LOG(ANIMAL_SOUND, WHITE)
}
