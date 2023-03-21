/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:47:00 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/08 17:23:08 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#define CLASSNAME "Dog"
#define ANIMAL_SOUND "wouaf"

Dog::Dog() : Animal(), _brain(new Brain())
{
	LOG_DEFAULT_CONSTRUCTOR(CLASSNAME)
	type = CLASSNAME;
	LOG_NEWLINE
}

Dog::Dog(const Dog &other) : Animal(), _brain(NULL)
{
	LOG_COPY_CONSTRUCTOR(CLASSNAME)
	*this = other;
	LOG_NEWLINE
}

Dog::~Dog()
{
	LOG_NEWLINE
	LOG_DESTRUCTOR(CLASSNAME)
	delete _brain;
}

Dog&	Dog::operator=(const Dog &other)
{
	LOG_OPERATOR_ASSIGN(CLASSNAME)
	if (this == &other)
		return *this;

	this->type = other.type;

	if (_brain)
		delete _brain;
	_brain = new Brain();
	*_brain = *other._brain;

	return *this;
}

void	Dog::makeSound(void) const
{
	LOG(ANIMAL_SOUND, WHITE)
}

Brain&	Dog::getBrain(void) const
{
	return *_brain;
}
