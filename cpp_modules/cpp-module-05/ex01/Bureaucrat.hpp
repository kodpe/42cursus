/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:50:10 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/10 11:24:38 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
	public:
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
   	   ~Bureaucrat ();
		Bureaucrat & operator=(const Bureaucrat &other);

		const std::string&	getName(void) const;
		int		getGrade(void) const;
		void	upgrade(void);
		void	downgrade(void);
		void	isvalidGrade(const int grade) const;

		void	signForm(Form &form) const;

	private:
		const std::string	_name;
		int					_grade;		// [1,150]
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bur);

#endif /* BUREAUCRAT_CLASS_HPP */
