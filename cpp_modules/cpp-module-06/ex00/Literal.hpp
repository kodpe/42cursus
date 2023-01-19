/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:26:29 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/15 02:09:54 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITERAL_CLASS_HPP
# define LITERAL_CLASS_HPP

#include <iostream>
#include <string>
#include <iomanip>		// std::setprecision
#include <limits>		// std::numeric_limits
#include <cmath> 		// fmod()
#include <cstdlib>		// strof() strod()
#include <sstream>		// std::ostringstream

#define DEBUG 0

#define LOG(x) 			if (DEBUG) { \
							std::cerr 	<< "\033[33mDEBUG : " << x \
										<< "\033[0m" << std::endl; }

#define DBG(name,value) if (DEBUG) { \
							std::cerr 	<< "\033[33mDEBUG : " \
										<< name << " : '" << value \
										<< "'\033[0m" << std::endl; }

#define TO_STR(x)		static_cast<std::ostringstream&>( \
    						(std::ostringstream() << std::dec << x)).str()

#define CHAR_MAX	std::numeric_limits<char>::max()
#define CHAR_MIN 	std::numeric_limits<char>::min()
#define INT_MAX		std::numeric_limits<int>::max()
#define INT_MIN		std::numeric_limits<int>::min()
#define	FLOAT_MAX	std::numeric_limits<float>::max()
#define FLOAT_MIN	-FLOAT_MAX
#define FLOAT_INF	std::numeric_limits<float>::infinity()
#define DOUBLE_MAX	std::numeric_limits<double>::max()
#define DOUBLE_MIN	-DOUBLE_MAX
#define DOUBLE_INF	std::numeric_limits<double>::infinity()

class Literal
{
	public:
		Literal();
		Literal(const std::string &str);
		Literal(const Literal &other);
   	   ~Literal();
		Literal& operator=(const Literal &other);

		bool	displayConv(void) const;

	private:
		std::string _str;

		/* *** CONV UTILS *** */
		bool	isSpecialValue(void) const;
		bool	convFromChar(void) const;
		bool	convFromInt(void) const;
		bool	convFromFloat(void) const;
		bool	convFromDouble(void) const;

		/* *** PRINT FUNCTIONS *** */
		void	print(const char c) const;
		void	print(const int c) const;
		void	print(const float f) const;
		void	print(const double f) const;
		void	printImpossible(const char* type) const;
		int		fractionalPartSize(void) const;
};

#endif /* LITERAL_CLASS_HPP */
