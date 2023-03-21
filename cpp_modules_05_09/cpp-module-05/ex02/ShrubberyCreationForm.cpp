/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:44:09 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/10 14:24:47by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#define JUNGLE "\
               ,@@@@@@@,                    \n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.        \n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o      \n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'   \n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'    \n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'     \n\
   `&%\\ ` /%&'    |.|        \\ '|8'       \n\
       |o|        | |         | |           \n\
       |.|        | |         | |           \n\
    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n\
"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137),
	_target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm(other),
	_target(other._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->_target = other._target;
	return *this;
}

const std::string&	ShrubberyCreationForm::getTarget(void) const
{
	return _target;
}

void	ShrubberyCreationForm::exec(void) const
{
	std::string		filename(_target + "_shrubbery");
	std::ofstream	output(filename.c_str());
	if (!output) {
		std::cerr << "ShrubberyCreationForm:: error can't open '" << filename << "'" << std::endl;
		return ;
	}
	output << JUNGLE << std::endl;
	output.close();
}

std::ostream&	operator<<(std::ostream &out, const ShrubberyCreationForm& form)
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

