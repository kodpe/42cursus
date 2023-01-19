/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:38:28 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/10 18:32:08 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_CLASS_HPP
# define ROBOTOMYREQUESTFORM_CLASS_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
   	   ~RobotomyRequestForm ();
		RobotomyRequestForm & operator=(const RobotomyRequestForm &other);

		const std::string&	getTarget(void) const;

	private:
		std::string	_target;

		void	exec(void) const;

};

std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm& form);

#endif /* ROBOTOMYREQUESTFORM_CLASS_HPP */
