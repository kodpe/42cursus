/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:58:22 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/13 15:29:44 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern::~Intern() {}

Intern&	Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

/******************************************************************************/

AForm*	Intern::makeShrubberyCreationForm(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::makeRobotomyRequestForm(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::makePresidentialPardonForm(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	t_form	form[3] = {
		{"shrubbery creation", &Intern::makeShrubberyCreationForm},
		{"robotomy request", &Intern::makeRobotomyRequestForm},
		{"presidential pardon", &Intern::makePresidentialPardonForm}
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == form[i].name)
		{
			std::cout << "\033[0;49;36m";
			std::cout << "Intern creates '" << name << "'" << std::endl;
			std::cout << "\033[0m";
			return (this->*form[i].fnct)(target);
		}
	}
	std::cout << "\033[0;49;33m";
	std::cout << "Can't make '" << name << "', unknown form name." << std::endl;
	std::cout << "\033[0m";
	return NULL;
}
