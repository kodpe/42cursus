/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:50:00 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/23 14:31:16 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>

#define PHONEBOOK_SIZEMAX 8

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		int		size();
		void	add_contact();
		void	search_contact();
		void	show_contact_list();
		void	filler();

	private:
		Contact	_contact[PHONEBOOK_SIZEMAX];
		int		_size;
		int		_oldest_id;

		std::string	_align_right(std::string const str, size_t const length);
		int			_get_id();
		void		_add_co(std::string const firstname,
							std::string const lastname,
							std::string const nickname,
							std::string const phone_number,
							std::string const darkest_secret);
};

#endif /* PHONEBOOK_H */

