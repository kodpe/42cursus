/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:22:47 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/03 18:11:55by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#define CLASSNAME "WrongAnimal"
#define ANIMAL_SOUND "..."

WrongAnimal::WrongAnimal() : type(CLASSNAME)
{
	LOG_DEFAULT_CONSTRUCTOR(CLASSNAME)
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	LOG_COPY_CONSTRUCTOR(CLASSNAME)
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	LOG_NEWLINE
	LOG_DESTRUCTOR(CLASSNAME)
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &other)
{
	LOG_OPERATOR_ASSIGN(CLASSNAME)
	this->type = other.type;
	return *this;
}

const std::string&	WrongAnimal::getType(void) const
{
	return this->type;
}

void	WrongAnimal::makeSound(void) const
{
	LOG(ANIMAL_SOUND, WHITE)
}
