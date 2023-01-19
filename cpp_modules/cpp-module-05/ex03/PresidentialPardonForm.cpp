/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:00:24 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/13 15:25:52 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5),
	_target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm(other),
	_target(other._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	this->_target = other._target;
	return *this;
}

const std::string&	PresidentialPardonForm::getTarget(void) const
{
	return _target;
}

void	PresidentialPardonForm::exec(void) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream&	operator<<(std::ostream &out, const PresidentialPardonForm& form)
{
	out	<< " ===== =====  " << std::endl
		<< " AForm name  : " << form.getName() << std::endl
		<< " is signed  : " << form.getStatut() << std::endl
		<< " sign grade : " << form.getGradeSign() << std::endl
		<< " exec grade : " << form.getGradeExec() << std::endl
		<< " target     : " << form.getTarget() << std::endl
		<< " ===== =====  " << std::endl;
	return out;
}
