/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:32:31 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/10 16:00:07 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "Form::GradeTooHighException";
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return "Form::GradeTooLowException";
}

const char* Form::AlreadySigned::what(void) const throw()
{
	return "Form::AlreadySigned";
}

void	Form::isvalidGrade(const int grade) const
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form() :
	_name("default"),
	_signed(false),
	_sign_grade(1),
	_exec_grade(1)
{
}

Form::Form(const std::string &name, int sign_grade, int exec_grade) :
	_name(name),
	_signed(false),
	_sign_grade(sign_grade),
	_exec_grade(exec_grade)
{
	isvalidGrade(sign_grade);
	isvalidGrade(exec_grade);
}

Form::Form(const Form &other) :
	_name(other._name),
	_signed(other._signed),
	_sign_grade(other._sign_grade),
	_exec_grade(other._exec_grade)
{
	isvalidGrade(other._sign_grade);
	isvalidGrade(other._exec_grade);
}

Form::~Form() {}

Form&	Form::operator=(const Form &other)
{
	this->_signed = other._signed;
	return *this;
}

const std::string& Form::getName(void) const
{
	return _name;
}

bool Form::getStatut(void) const
{
	return _signed;
}

int Form::getGradeSign(void) const
{
	return _sign_grade;
}

int Form::getGradeExec(void) const
{
	return _exec_grade;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	isvalidGrade(bureaucrat.getGrade());
	if (bureaucrat.getGrade() > _sign_grade)
		throw Form::GradeTooLowException();
	if (_signed == true)
		throw Form::AlreadySigned();
	_signed = true;
}

std::ostream&	operator<<(std::ostream &out, const Form &form)
{
	out	<< " ===== =====  " << std::endl
		<< " Form name  : " << form.getName() << std::endl
		<< " is signed  : " << form.getStatut() << std::endl
		<< " sign grade : " << form.getGradeSign() << std::endl
		<< " exec grade : " << form.getGradeExec() << std::endl
		<< " ===== =====  " << std::endl;
	return out;
}
