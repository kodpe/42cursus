/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:56:12 by sloquet           #+#    #+#             */
/*   Updated: 2023/04/25 11:07:54 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const char *database);
		BitcoinExchange(BitcoinExchange const & other);
		~BitcoinExchange();
		BitcoinExchange & operator=(BitcoinExchange const & other);

		void	read_file(const char *file, bool (BitcoinExchange::*f)(std::string &));
		bool	eval_line(std::string & line);

	private:
		std::map<std::string, double>	_mymap;
		bool	add_line(std::string & line);
};

int		sc_strtod(const char *str, double *nb, char next);
bool	date_isvalid(std::string str);

#endif /* BITCOINEXCHANGE_HPP */
