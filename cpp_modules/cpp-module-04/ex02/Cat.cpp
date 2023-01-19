/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:47:00 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/08 17:22:52 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#define CLASSNAME "Cat"
#define ANIMAL_SOUND "miaou"

Cat::Cat() : Animal(), _brain(new Brain())
{
	LOG_DEFAULT_CONSTRUCTOR(CLASSNAME)
	type = CLASSNAME;
	LOG_NEWLINE
}

Cat::Cat(const Cat &other) : Animal(), _brain(NULL)
{
	LOG_COPY_CONSTRUCTOR(CLASSNAME)
	*this = other;
	LOG_NEWLINE
}

Cat::~Cat()
{
	LOG_NEWLINE
	LOG_DESTRUCTOR(CLASSNAME)
	delete _brain;
}

Cat&	Cat::operator=(const Cat &other)
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

void	Cat::makeSound(void) const
{
	LOG(ANIMAL_SOUND, WHITE)
}

Brain&	Cat::getBrain(void) const
{
	return *_brain;
}
