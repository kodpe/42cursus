/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CONTACT.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:50:00 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/17 18:20:57 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class	Contact
{
	public:
		Contact();
		~Contact();

		bool	set_firstname(std::string const firstname);
		bool	set_lastname(std::string const lastname);
		bool	set_nickname(std::string const nickname);
		bool	set_phone_number(std::string const phone_number);
		bool	set_darkest_secret(std::string const darkest_secret);

		std::string	get_firstname();
		std::string	get_lastname();
		std::string	get_nickname();
		std::string	get_phone_number();
		std::string	get_darkest_secret();

		void	show();

	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;

		std::string	_trim(std::string const src);
		bool		_valid_phone(std::string const src);
		bool		_valid_name(std::string const src);
};

#endif /* CONTACT_H */

