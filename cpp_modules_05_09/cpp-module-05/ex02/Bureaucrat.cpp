/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:39:13 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/13 15:19:56 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat::GradeTooHighException : maximum grade is 1");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat::GradeTooLowException : minimum grade is 150");
}

void	Bureaucrat::isvalidGrade(const int grade) const
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) :
						_name(name),
						_grade(150)
{
	isvalidGrade(grade);
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat assignation operator" << std::endl;
	isvalidGrade(other._grade);
	this->_grade = other._grade;
	return *this;
}

const std::string& Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::upgrade(void)
{
	isvalidGrade(_grade - 1);
	_grade -= 1;
	std::cout << _name << " bureaucrat upgrade, new grade " << _grade << "." << std::endl;
}

void	Bureaucrat::downgrade(void)
{
	isvalidGrade(_grade + 1);
	_grade += 1;
	std::cout << _name << " bureaucrat downgrade, new grade " << _grade << "." << std::endl;
}

void	Bureaucrat::signForm(AForm &Aform) const
{
	try {
		Aform.beSigned(*this);
		std::cout << "\033[2;49;32m";
		std::cout	<< this->_name << " signed "
					<< Aform.getName() << "." << std::endl;
		std::cout << "\033[0m";
	}
	catch (AForm::AlreadySigned &e) {
		std::cout << "\033[0;49;33m";
		std::cout	<< this->_name << " couldn't sign "
					<< Aform.getName() << " because "
					<< e.what() << "." << std::endl;
		std::cout << "\033[0m";
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << "\033[0;49;33m";
		std::cout	<< this->_name << " couldn't sign "
					<< Aform.getName() << " because "
					<< e.what() << "." << std::endl;
		std::cout << "\033[0m";
	}
}

void	Bureaucrat::executeForm(AForm &Aform)
{
	try {
		Aform.execute(*this);
		std::cout << "\033[2;49;32m";
		std::cout	<< this->_name << " executed "
					<< Aform.getName() << "." << std::endl;
		std::cout << "\033[0m";
	}
	catch (AForm::NotSigned &e) {
		std::cout << "\033[0;49;33m";
		std::cerr	<< this->_name << " couldn't execute "
					<< Aform.getName() << " because "
					<< e.what() << "." << std::endl;
		std::cout << "\033[0m";
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << "\033[0;49;33m";
		std::cerr	<< this->_name << " couldn't execute "
					<< Aform.getName() << " because "
					<< e.what() << "." << std::endl;
		std::cout << "\033[0m";
	}
}

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return (out);
}
