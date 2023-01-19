/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:38:28 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/10 18:32:08 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_CLASS_HPP
# define PRESIDENTIALPARDONFORM_CLASS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
   	   ~PresidentialPardonForm ();
		PresidentialPardonForm & operator=(const PresidentialPardonForm &other);

		const std::string&	getTarget(void) const;

	private:
		std::string	_target;

		void	exec(void) const;

};

std::ostream&	operator<<(std::ostream& out, const PresidentialPardonForm& form);

#endif /* PRESIDENTIALPARDONFORM_CLASS_HPP */
