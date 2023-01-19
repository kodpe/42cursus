/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:18:53 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/15 02:31:16 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Literal.hpp"

Literal::Literal() : _str("") {}

Literal::Literal(const std::string &str) : _str(str) {}

Literal::Literal(const Literal &other) : _str(other._str) {}

Literal::~Literal() {}

Literal&	Literal::operator=(const Literal &other)
{
	this->_str = other._str;
	return *this;
}

/* *** CONV UTILS *** */
bool	Literal::isSpecialValue(void) const
{
	if (_str == "-inff" || _str == "+inff" || _str == "inff" || _str == "nanf"
	 || _str == "-inf"  || _str == "+inf"  || _str == "inf"  || _str == "nan")
	{
		LOG("special value detected")
		return true;
	}
	return false;
}

bool	Literal::convFromChar(void) const
{
	char	c = _str[0];

	if (_str.size() == 3)
		c = _str[1];

	DBG("-> input as char", _str)
	DBG("char c", c);

	print(c);
	print(static_cast<int>(c));
	print(static_cast<float>(c));
	print(static_cast<double>(c));
	return true;
}

bool	Literal::convFromInt(void) const
{
	int	i 				= atoi(_str.c_str());
	std::string tostr	= TO_STR(i);

	DBG("-> input as int", _str)
	DBG("int i", i);
	DBG("tostr", tostr);

	if (tostr.size() != _str.size() || (_str[0] != '-' && tostr[0] == '-'))
		return false;

	if (i < CHAR_MIN || i > CHAR_MAX)
		printImpossible("char");
	else
		print(static_cast<char>(i));
	print(i);
	print(static_cast<float>(i));
	print(static_cast<double>(i));
	return true;
}

bool	Literal::convFromFloat(void) const
{

	const char	*end 	= "";
	char* 		endptr	= (char*)end;
	float		f		= std::strtof(_str.c_str(), &endptr);

	DBG("-> input as float", _str)
	DBG("endptr", endptr);
	DBG("float f", f);

	if (endptr[0] != 'f' || endptr[1] || _str[0] == '.' || _str[_str.size() - 2 ] == '.')
		return false;

	if (f < CHAR_MIN || f > CHAR_MAX || isSpecialValue())
		printImpossible("char");
	else
		print(static_cast<char>(f));

	if (f < INT_MIN || f > INT_MAX || isSpecialValue())
		printImpossible("int");
	else
		print(static_cast<int>(f));

	print(f);
	print(static_cast<double>(f));
	return true;
}

bool	Literal::convFromDouble(void) const
{
	const char	*end	= "";
	char* 		endptr 	= (char*)end;
	double		d 		= std::strtod(_str.c_str(), &endptr);

	DBG("-> input as double", _str);
	DBG("double d", d);
	DBG("endptr", endptr);

	if (endptr[0] || _str[0] == '.' || _str[_str.size() - 1 ] == '.')
		return false;

	if (d < CHAR_MIN || d > CHAR_MAX || isSpecialValue())
		printImpossible("char");
	else
		print(static_cast<char>(d));

	if (d < INT_MIN || d > INT_MAX || isSpecialValue())
		printImpossible("int");
	else
		print(static_cast<int>(d));
	
	if ((d < FLOAT_MIN || d > FLOAT_MAX) && !isSpecialValue()
		&& d != DOUBLE_INF && d != -DOUBLE_INF)
		printImpossible("float");
	else
		print(static_cast<float>(d));
	
	print(d);
	return true;
}

bool	Literal::displayConv(void) const
{
	int	c = static_cast<int>(_str[0]);

	if (_str.empty() || not std::isprint(_str[0]))
		return false;

	if (_str.size() == 1 && ! std::isdigit(c))
		return convFromChar();

	if (_str.size() == 3 && _str[0] == '\'' && std::isprint(_str[1]) && _str[2] == '\'')
		return convFromChar();

	if (_str == "-inff" || _str == "+inff" || _str == "inff" || _str == "nanf")
		return convFromFloat();

	if (_str == "-inf" || _str == "+inf" || _str == "inf" || _str == "nan")
		return convFromDouble();

	if (_str.find('f') != std::string::npos && _str.find('.') != std::string::npos)
		return convFromFloat();

	if (_str.find('.') != std::string::npos)
		return convFromDouble();

	return convFromInt();
}

/* *** PRINT FUNCTIONS *** */

int		Literal::fractionalPartSize(void) const
{
	if (_str.find('.') == std::string::npos || _str[0] == '.' || _str[0] == '\'')
		return 1;
	if (_str.find('f') != std::string::npos)
		return _str.substr(_str.find('.')).size() - 2; 	// is float
	return _str.substr(_str.find('.')).size() - 1; 		// is double
}

void	Literal::print(const char c) const
{
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
}

void	Literal::print(const int i) const
{
	std::cout << "int: " << i << std::endl;
}

void	Literal::print(const float f) const
{
	std::cout << std::setprecision(fractionalPartSize()) << std::fixed;
	std::cout << "float: " << f << "f" << std::endl;
}

void	Literal::print(const double d) const
{
	std::cout << std::setprecision(fractionalPartSize()) << std::fixed;
	std::cout << "double: " << d << std::endl;
}

void	Literal::printImpossible(const char* type) const
{
		std::cout << type << ": impossible" << std::endl;
}
