/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:37:27 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/29 17:55:06 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : _size(0), _oldest_id(0) {}

PhoneBook::~PhoneBook() {}

int	PhoneBook::size()
{
	return _size;
}

void	PhoneBook::_add_co(	std::string const firstname,
							std::string const lastname,
							std::string const nickname,
							std::string const phone_number,
							std::string const darkest_secret)
{
	int	id(_get_id());

	_contact[id].set_firstname(firstname);
	_contact[id].set_lastname(lastname);
	_contact[id].set_nickname(nickname);
	_contact[id].set_phone_number(phone_number);
	_contact[id].set_darkest_secret(darkest_secret);
}

std::string	PhoneBook::_align_right(std::string const str, size_t const length)
{
	std::string	spaces("");

	if (length <= 0)
		return str;

	if (str.length() > length)
		return (str.substr(0, 9) + ".");

	for (size_t i = 0; i <  length - str.length(); i++)
		spaces += " ";
	return (spaces + str);
}

void	PhoneBook::filler()
{
	_add_co("ABC", "abc", "a b c", "123", "secret 1");
	_add_co("DEF", "def", "d e f", "123 456", "secret 2");
	_add_co("GHI", "ghi", "  g  h  i  ", "0123456789", "secret 3");
	_add_co("JKL", "jkl", "jk", "344-495-392", "secret 4");
	_add_co("MNO", "mno", "mno  mno", "55", "secret 5");
	_add_co("PQR", "pqr", "pqr pqr", "66 66", "secret 6");
	_add_co("STU", "stu", "stu", " 7  7  7 ", "secret 7");
	_add_co("VWX", "vwx", "x", "+330652424374", "secret 8");
}

int		PhoneBook::_get_id()
{
	int		id;

	id = _size;

	if (_size == PHONEBOOK_SIZEMAX)
	{
		id = _oldest_id;
		_oldest_id += 1;
		if (_oldest_id == PHONEBOOK_SIZEMAX)
			_oldest_id = 0;
	}
	else
		_size++;
	return (id);
}

void	PhoneBook::add_contact()
{
	std::string	input;
	int			id(_get_id());

	do {
		if (std::cin.eof())
			return ;
		std::cout << "first name : ";
		if (not std::getline(std::cin, input))
			break ;
	}
	while (not _contact[id].set_firstname(input));

	do {
		if (std::cin.eof())
			return ;
		std::cout << "last name : ";
		if (not std::getline(std::cin, input))
			break ;
	}
	while (not _contact[id].set_lastname(input));

	do {
		if (std::cin.eof())
			return ;
		std::cout << "nickname : ";
		if (not std::getline(std::cin, input))
			break ;
	}
	while (not _contact[id].set_nickname(input));

	do {
		if (std::cin.eof())
			return ;
		std::cout << "phone number : ";
		if (not std::getline(std::cin, input))
			break ;
	}
	while (not _contact[id].set_phone_number(input));

	do {
		if (std::cin.eof())
			return ;
		std::cout << "darkest secret : ";
		if (not std::getline(std::cin, input))
			break ;
	}
	while (not _contact[id].set_darkest_secret(input));

	if (std::cin.eof())
		return ;
	std::cout << "Done!" << std::endl;
}

void	PhoneBook::search_contact()
{
	std::string	input;

	show_contact_list();
	if (size() == 0)
		return ;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "select an index: ";
		if (not std::getline(std::cin, input) or input.empty())
			break ;
		if (input.length() == 1 && std::isdigit(input[0]))
		{
			int	id(input[0] - 48 - 1);

			if (id >= 0 && id < _size)
			{
				_contact[id].show();
				break ;
			}
		}
		std::cout << "unknown index '" << input << "'" << std::endl;
	}
}

void	PhoneBook::show_contact_list()
{
	std::cout << "|   index  |first name| last name| nickname |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < _size; i++)
	{
		std::cout << "|         " << i + 1 << "|";
		std::cout << _align_right(_contact[i].get_firstname(), 10) << "|";
		std::cout << _align_right(_contact[i].get_lastname(), 10) << "|";
		std::cout << _align_right(_contact[i].get_nickname(), 10) << "|";
		std::cout << std::endl;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}
