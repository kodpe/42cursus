/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:38:28 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/10 18:32:08 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP
# define SHRUBBERYCREATIONFORM_CLASS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
   	   ~ShrubberyCreationForm ();
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &other);

		const std::string&	getTarget(void) const;

	private:
		std::string	_target;

		void	exec(void) const;

};

std::ostream&	operator<<(std::ostream& out, const ShrubberyCreationForm& form);

#endif /* SHRUBBERYCREATIONFORM_CLASS_HPP */
