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

#define LOG(x) std::cout << "\n\033[34m<> " << x << " <>\033[0m\n";

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
		Bureaucrat paul = Bureaucrat("paul", 142);

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

	return 0;
}
