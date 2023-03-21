/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:47:00 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/08 16:41:02 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#define CLASSNAME "Cat"
#define ANIMAL_SOUND "miaou"

Cat::Cat() : Animal()
{
	LOG_DEFAULT_CONSTRUCTOR(CLASSNAME)
	type = CLASSNAME;
}

Cat::Cat(const Cat &other) : Animal()
{
	LOG_COPY_CONSTRUCTOR(CLASSNAME)
	*this = other;
}

Cat::~Cat()
{
	LOG_DESTRUCTOR(CLASSNAME)
}

Cat&	Cat::operator=(const Cat &other)
{
	LOG_OPERATOR_ASSIGN(CLASSNAME)
	this->type = other.type;
	return *this;
}

void	Cat::makeSound(void) const
{
	LOG(ANIMAL_SOUND, WHITE)
}
