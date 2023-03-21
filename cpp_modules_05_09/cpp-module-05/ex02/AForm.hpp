/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:32:17 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/10 12:55:00 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CLASS_HPP
# define AFORM_CLASS_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
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

		class NotSigned : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		AForm();
		AForm(const std::string &name, int sign_grade, int exec_grade);
		AForm(const AForm &other);
   	    virtual ~AForm ();
		AForm & operator=(const AForm &other);

		void				isvalidGrade(const int grade) const;
		const std::string&	getName(void) const;
		bool				getStatut(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;

		void			beSigned(const Bureaucrat &bureaucrat);

		void	execute(const Bureaucrat &executor) const;

	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;

		virtual void	exec(void) const = 0;

};

std::ostream&	operator<<(std::ostream &out, const AForm& Aform);

#endif /* AFORM_CLASS_HPP */
