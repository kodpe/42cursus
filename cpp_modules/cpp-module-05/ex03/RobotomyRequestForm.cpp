/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:00:54 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/13 15:26:01 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45),
	_target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other),
	_target(other._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	this->_target = other._target;
	return *this;
}

const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return _target;
}

void	RobotomyRequestForm::exec(void) const
{
	std::cout << "* some drilling noises * VRRRRZZZZZZZZZZZZ" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully";
	else
		std::cout << _target << " robotomy failed";
	std::cout << std::endl;
}

std::ostream&	operator<<(std::ostream &out, const RobotomyRequestForm& form)
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

