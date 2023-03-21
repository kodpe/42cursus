/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:47:00 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/08 16:40:59 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#define CLASSNAME "Dog"
#define ANIMAL_SOUND "wouaf"

Dog::Dog() : Animal()
{
	LOG_DEFAULT_CONSTRUCTOR(CLASSNAME)
	type = CLASSNAME;
}

Dog::Dog(const Dog &other) : Animal()
{
	LOG_COPY_CONSTRUCTOR(CLASSNAME)
	*this = other;
}

Dog::~Dog()
{
	LOG_DESTRUCTOR(CLASSNAME)
}

Dog&	Dog::operator=(const Dog &other)
{
	LOG_OPERATOR_ASSIGN(CLASSNAME)
	this->type = other.type;
	return *this;
}

void	Dog::makeSound(void) const
{
	LOG(ANIMAL_SOUND, WHITE)
}
