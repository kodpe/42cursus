/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:36:57 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/10 15:59:18 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return "AForm::GradeTooHighException";
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return "AForm::GradeTooLowException";
}

const char* AForm::AlreadySigned::what(void) const throw()
{
	return "AForm::AlreadySigned";
}

const char* AForm::NotSigned::what(void) const throw()
{
	return "AForm::NotSigned";
}

void	AForm::isvalidGrade(const int grade) const
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm() :
	_name("default"),
	_signed(false),
	_sign_grade(1),
	_exec_grade(1)
{
}

AForm::AForm(const std::string &name, int sign_grade, int exec_grade) :
	_name(name),
	_signed(false),
	_sign_grade(sign_grade),
	_exec_grade(exec_grade)
{
	isvalidGrade(sign_grade);
	isvalidGrade(exec_grade);
}

AForm::AForm(const AForm &other) :
	_name(other._name),
	_signed(other._signed),
	_sign_grade(other._sign_grade),
	_exec_grade(other._exec_grade)
{
	isvalidGrade(other._sign_grade);
	isvalidGrade(other._exec_grade);
}

AForm::~AForm() {}

AForm&	AForm::operator=(const AForm &other)
{
	this->_signed = other._signed;
	return *this;
}

const std::string& AForm::getName(void) const
{
	return _name;
}

bool AForm::getStatut(void) const
{
	return _signed;
}

int AForm::getGradeSign(void) const
{
	return _sign_grade;
}

int AForm::getGradeExec(void) const
{
	return _exec_grade;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	isvalidGrade(bureaucrat.getGrade());
	if (bureaucrat.getGrade() > _sign_grade)
		throw AForm::GradeTooLowException();
	if (_signed == true)
		throw AForm::AlreadySigned();
	_signed = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	isvalidGrade(executor.getGrade());
	if (_signed == false)
		throw AForm::NotSigned();
	if (executor.getGrade() > _exec_grade)
		throw AForm::GradeTooLowException();
	exec();
}

std::ostream&	operator<<(std::ostream &out, const AForm &Aform)
{
	out	<< " ===== =====  " << std::endl
		<< " AForm name  : " << Aform.getName() << std::endl
		<< " is signed  : " << Aform.getStatut() << std::endl
		<< " sign grade : " << Aform.getGradeSign() << std::endl
		<< " exec grade : " << Aform.getGradeExec() << std::endl
		<< " ===== =====  " << std::endl;
	return out;
}
