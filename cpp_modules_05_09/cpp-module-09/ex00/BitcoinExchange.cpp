/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:56:06 by sloquet           #+#    #+#             */
/*   Updated: 2023/04/25 11:22:17 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#define ER_UNOPEN "Error: could not open file : "
#define	ER_EMPTYD "Error: database is empty."
#define ER_BADINP "Error: bad input => "
#define ER_NEGNUM "Error: not a positive number."
#define ER_MAXNUM "Error: too large number."

BitcoinExchange::BitcoinExchange(): _mymap()
{
}

BitcoinExchange::BitcoinExchange(const char *database): _mymap()
{
	read_file(database, &BitcoinExchange::add_line);
	if (_mymap.size() == 0)
		throw std::invalid_argument(ER_EMPTYD);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & other)
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & other)
{
	if (this != &other)
		_mymap = other._mymap;
	return *this;
}

void	BitcoinExchange::read_file(const char *file, bool (BitcoinExchange::*f)(std::string &))
{
	std::ifstream	is(file);
	if (!is)
		throw std::invalid_argument(ER_UNOPEN + std::string(file));

	std::string		line;
	std::getline(is, line, '\n');
	if (!is.good())
		throw std::invalid_argument(ER_UNOPEN + std::string(file));
	int	i = 2;
	while (1)
	{
		std::getline(is, line, '\n');
		if (!is.good())
			break ;
		if (is.eof())
			break ;
		if (line.empty())
			continue ;
		if (!(this->*f)(line)) {
			std::cout << file << ":" << i << std::endl;
			break ;
		}
		++i;
	}
	is.close();
}

bool	BitcoinExchange::add_line(std::string & line)
{
	if (line.find(",") == std::string::npos || line[line.size() - 1] == ',') {
		std::cout << ER_BADINP << "'" << line << "'" << std::endl;
		return false;
	}

	std::string	date = line.substr(0, line.find(","));
	std::string strval = line.substr(line.find(",") + 1);

	if (!date_isvalid(date)) {
		std::cout << ER_BADINP << "'" << line << "'" << std::endl;
		return false;
	}

	double value;
	if (strval.empty() || sc_strtod(strval.c_str(), &value, 0)) {
		std::cout << ER_BADINP << "'" << line << "'" << std::endl;
		return false;
	}
	if (value < 0) {
		std::cout << ER_NEGNUM << "'" << line << "'" << std::endl;
		return false;
	}
	_mymap[date] = value;
	return true;
}

bool BitcoinExchange::eval_line(std::string & line)
{
	if (line.find("|") == std::string::npos || line[line.size() - 1] == '|') {
		std::cout << ER_BADINP << "'" << line << "'" << std::endl;
		return true;
	}

	std::string date = line.substr(0, line.find("|") -1);
	std::string strval = line.substr(line.find("|") + 2);

	if (_mymap.size() == 0 || !date_isvalid(date)) {
		std::cout << ER_BADINP << "'" << line << "'" << std::endl;
		return true;
	}
	double value;
	if (strval.empty() || sc_strtod(strval.c_str(), &value, 0)) {
		std::cout << ER_BADINP << "'" << line << "'" << std::endl;
		return true;
	}
	if (value < 0) {
		std::cout << ER_NEGNUM << std::endl;
		return true;
	}
	if (value > 1000) {
		std::cout << ER_MAXNUM << std::endl;
		return true;
	}

	std::map<std::string, double>::reverse_iterator rv;
	rv = _mymap.rbegin();
	if (rv->first < date)
	{
		std::cout << date << " => " << value << " = "
				  << rv->second * value << std::endl;
		return true;
	}

	std::map<std::string, double>::iterator it;
	it = _mymap.begin();
	if (it->first > date)
	{
		std::cout << ER_BADINP << "'" << date << "'" << std::endl;
		return true;
	}

	it = _mymap.lower_bound(date);
	if (it == _mymap.end()) {
		std::cout << ER_BADINP << "'" << date << "'" << std::endl;
		return true;
	}
	std::cout << date << " => " << value << " = " << it->second * value << std::endl;
	return true;
}
