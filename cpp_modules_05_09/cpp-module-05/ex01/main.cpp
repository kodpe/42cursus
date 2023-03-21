/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:36:09 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/08 20:56:54by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define LOG(x) std::cout << "\n\033[34m<> " << x << " <>\033[0m\n";
#define LOGN(x) std::cout << x;

int	main(void)
{
	LOG("TEST 1 : GradeTooHighException : init too high")
	try {
		Bureaucrat max = Bureaucrat("max", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}

	LOG("TEST 2 : GradeTooLowException : init too low")
	try {
		Bureaucrat ash = Bureaucrat("ash", 151);
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	LOG("TEST 3 : GradeTooHighException : upgrade limit")
	try {
		Bureaucrat joe = Bureaucrat("joe", 3);
		std::cout << joe << std::endl;
		joe.upgrade();
		joe.upgrade();
		joe.upgrade();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}

	LOG("TEST 4 : GradeTooLowException : downgrade limit")
	try {
		Bureaucrat mia = Bureaucrat("mia", 148);
		std::cout << mia << std::endl;
		mia.downgrade();
		mia.downgrade();
		mia.downgrade();
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	LOG("TEST 5 : Bureaucrat accessors")
	try {
		Bureaucrat paul = Bureaucrat("paul", 42);

		std::cout << "getName() : " << paul.getName() << std::endl;
		std::cout << "getGrade(): " << paul.getGrade() << std::endl;
		std::cout << "operator<<: " << paul << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	LOG("TEST 6 : Invalid forms")
	try {
		LOGN("Form	f1 = Form(\"f1\", 0, 42)   : ");

		Form	f1 = Form("f1", 0, 42);
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		LOGN("Form	f2 = Form(\"f2\", 42, 0)   : ");

		Form	f2 = Form("f2", 42, 0);
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		LOGN("Form	f3 = Form(\"f3\", 151, 42) : ");

		Form	f3 = Form("f3", 151, 42);
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		LOGN("Form	f4 = Form(\"f4\", 42, 151) : ");

		Form	f4 = Form("f4", 42, 151);
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	LOG("TEST 7 : Valid forms")
	try {
		LOGN("Form	f5 = Form(\"f5\", 1, 150);\n");
		Form	f5 = Form("f5", 1, 150);
		std::cout << f5 << std::endl;

		LOGN("Form	f6 = Form(\"f6\", 142, 64);\n");
		Form	f6 = Form("f6", 142, 64);
		std::cout << f6 << std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	LOG("TEST 8 : Sign forms")
	try {
		Form	f7 = Form("f7", 43, 1);
		Form	f8 = Form("f8", 42, 1);
		Form	f9 = Form("f9", 41, 1);

		std::cout << f7 << f8 << f9 << std::endl;

		Bureaucrat	paul = Bureaucrat("paul", 42);
		std::cout << paul << std::endl;
		paul.signForm(f7);
		paul.signForm(f8);
		paul.signForm(f9);
		paul.signForm(f7);

		// f7.beSigned(paul);
		// f8.beSigned(paul);
		// f9.beSigned(paul);
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Form::AlreadySigned &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
