/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:58:25 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/10 23:06:08 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
   	   ~Intern ();
		Intern & operator=(const Intern &other);

		AForm*	makeForm(const std::string name, const std::string target);

	private:
		AForm*	makeShrubberyCreationForm(const std::string &target) const;
		AForm*	makeRobotomyRequestForm(const std::string &target) const;
		AForm*	makePresidentialPardonForm(const std::string &target) const;

		typedef struct e_form
		{
			const std::string &name;
			AForm *(Intern::*fnct)(const std::string &target) const;
		} t_form;
};

#endif /* INTERN_CLASS_HPP */
