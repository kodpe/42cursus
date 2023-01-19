/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:32:17 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/10 11:28:56 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
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

		class AlreadySigned : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		Form();
		Form(const std::string &name, int sign_grade, int exec_grade);
		Form(const Form &other);
   	   ~Form ();
		Form & operator=(const Form &other);

		void				isvalidGrade(const int grade) const;
		const std::string&	getName(void) const;
		bool				getStatut(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;

		void	beSigned(const Bureaucrat &bureaucrat);

	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;
};

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif /* FORM_CLASS_HPP */
