/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:22:47 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/03 18:11:55by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#define CLASSNAME "Animal"
// #define ANIMAL_SOUND "..."

Animal::Animal() : type(CLASSNAME)
{
	LOG_DEFAULT_CONSTRUCTOR(CLASSNAME)
}

Animal::Animal(const Animal &other)
{
	LOG_COPY_CONSTRUCTOR(CLASSNAME)
	*this = other;
}

Animal::~Animal()
{
	LOG_DESTRUCTOR(CLASSNAME)
}

Animal&	Animal::operator=(const Animal &other)
{
	LOG_OPERATOR_ASSIGN(CLASSNAME)
	this->type = other.type;
	return *this;
}

const std::string&	Animal::getType(void) const
{
	return this->type;
}

// void	Animal::makeSound(void) const
// {
// 	LOG(ANIMAL_SOUND, WHITE)
// }
