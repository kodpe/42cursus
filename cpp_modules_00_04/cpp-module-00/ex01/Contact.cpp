/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:33:45 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/23 15:10:15 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <cctype>

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

std::string Contact::_trim(std::string const src)
{
	std::string	str(src);
	std::string	trimmed("");
	int			i;
	int			max;

	max = str.length() - 1;
	while (str[max] && not std::isgraph(str[max]))
		max--;
	for (i = 0; i <= max; i++)
	{
		if (not std::isgraph(str[i]))
		{
			if (str[i] == '\t' or str[i] == ' ')
				trimmed += " ";
			while (str[i] && not std::isgraph(str[i]))
				i++;
		}
		if (str[i])
			trimmed += str[i];
	}
	return trimmed;
}

bool	Contact::_valid_phone(std::string const src)
{
	std::string	str(src);
	int			count_digit(0);

	if (str.empty() or str.length() > 128)
		return false;
	for (int i = 0; str[i] ; i++)
	{
		if (not std::isdigit(str[i]) and str[i] != '+' and str[i] != '-' \
			and str[i] != ' ')
			return false;
		if (std::isdigit(str[i]))
			count_digit++;
	}
	if (count_digit < 2)
			return false;
	return true;
}

bool	Contact::_valid_name(std::string const src)
{
	std::string	str(src);
	int			count_alpha(0);

	if (str.empty() or str.length() > 128)
		return false;
	for (int i = 0; str[i] ; i++)
	{
		if (not std::isalpha(str[i]) and str[i] != '-' and str[i] != ' ')
			return false;
		if (std::isalpha(str[i]))
			count_alpha++;
	}
	if (count_alpha < 1)
			return false;
	return true;
}

bool	Contact::set_firstname(std::string const firstname)
{
	_firstname = _trim(firstname);
	return _valid_name(_firstname);
}

bool	Contact::set_lastname(std::string const lastname)
{
	_lastname = _trim(lastname);
	return _valid_name(_lastname);
}

bool	Contact::set_nickname(std::string const nickname)
{
	_nickname = _trim(nickname);
	return _valid_name(_nickname);
}

bool	Contact::set_phone_number(std::string const phone_number)
{
	_phone_number = _trim(phone_number);
	return _valid_phone(_phone_number);
}

bool	Contact::set_darkest_secret(std::string const darkest_secret)
{
	_darkest_secret = _trim(darkest_secret);
	return not _darkest_secret.empty();
}

std::string	Contact::get_firstname()
{
	return (_firstname);
}

std::string	Contact::get_lastname()
{
	return (_lastname);
}

std::string	Contact::get_nickname()
{
	return (_nickname);
}

std::string	Contact::get_phone_number()
{
	return (_phone_number);
}

std::string	Contact::get_darkest_secret()
{
	return (_darkest_secret);
}

void	Contact::show(void)
{
	std::cout << "first name     :" << _firstname << std::endl;
	std::cout << "last name      :" << _lastname << std::endl;
	std::cout << "nickname       :" << _nickname << std::endl;
	std::cout << "phone number   :" << _phone_number << std::endl;
	std::cout << "darkest secret :" << _darkest_secret << std::endl;
}
