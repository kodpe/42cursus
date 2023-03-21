/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:16:04 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/08 17:33:35 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#define CLASSNAME "Brain"
#define BRAIN_INDEX_ERROR "invalid idea index"

Brain::Brain()
{
	LOG_DEFAULT_CONSTRUCTOR(CLASSNAME)
	for (int i = 0; i < brain_size; i++)
		this->ideas[i] = "";
}

Brain::Brain(const Brain &other)
{
	LOG_COPY_CONSTRUCTOR(CLASSNAME)
	*this = other;
}

Brain::~Brain()
{
	LOG_DESTRUCTOR(CLASSNAME)
	for (int i = 0; i < brain_size; i++)
		this->ideas[i] = "";
}

Brain&	Brain::operator=(const Brain &other)
{
	LOG_OPERATOR_ASSIGN(CLASSNAME)
	if (this == &other)
		return *this;
	for (int i = 0; i < brain_size; i++)
		this->ideas[i] = other.ideas[i];
	return *this;
}

void	Brain::setIdea(int i, const std::string& new_idea)
{
	if (i < 0 || i > brain_size - 1)
	{
		LOG(BRAIN_INDEX_ERROR, RED);
		return ;
	}
	this->ideas[i] = new_idea;
}

const std::string	Brain::getIdea(int i) const
{
	if (i < 0 || i > brain_size - 1)
		return (BRAIN_INDEX_ERROR);
	return this->ideas[i];
}
