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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define LOG(x) 	std::cout << "\n\033[34m<> " << x << " <>\033[0m\n";
#define LOGN(x) std::cout << x;
// #define WHAT	std::cerr << e.what() << std::endl;

int	main(void)
{
	srand(time(NULL));
#if 0 /* TEST 1-5 Bureaucrat */

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

#endif

	{
		LOG("TEST 9  : ShrubberyCreationForm::")

		Bureaucrat	obelix	= Bureaucrat("Obelix", 146);
		Bureaucrat	asterix = Bureaucrat("Asterix", 136);
		AForm* A38 = new ShrubberyCreationForm("Home");

		std::cout << *A38 << std::endl;
		obelix.executeForm(*A38);
		obelix.signForm(*A38);
		asterix.signForm(*A38);
		asterix.signForm(*A38);
		obelix.executeForm(*A38);
		asterix.executeForm(*A38);
		delete A38;
	}
	{
		LOG("TEST 10 : RobotomyRequestForm::")

		Bureaucrat	obelix	= Bureaucrat("Obelix", 73);
		Bureaucrat	asterix = Bureaucrat("Asterix", 44);
		AForm*	A38 = new RobotomyRequestForm("Someone");
		std::cout << *A38 << std::endl;
		obelix.executeForm(*A38);
		obelix.signForm(*A38);
		asterix.signForm(*A38);
		asterix.signForm(*A38);
		obelix.executeForm(*A38);
		for (int i = 0; i < 10; i++)
			asterix.executeForm(*A38);
		delete A38;
	}
	{
		LOG("TEST 11 : PresidentialPardonForm::")

		Bureaucrat	obelix	= Bureaucrat("Obelix", 26);
		Bureaucrat	asterix = Bureaucrat("Asterix", 4);
		AForm*	A38 = new PresidentialPardonForm("Someone");
		std::cout << *A38 << std::endl;
		obelix.executeForm(*A38);
		obelix.signForm(*A38);
		asterix.signForm(*A38);
		asterix.signForm(*A38);
		obelix.executeForm(*A38);
		asterix.executeForm(*A38);
		delete A38;
	}

	std::cout << std::endl;
	return 0;
}
