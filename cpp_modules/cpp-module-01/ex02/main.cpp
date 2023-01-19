/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:02:22 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/24 21:22:22 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str("HI THIS IS BRAIN");

	std::string	*stringPTR;

	stringPTR = NULL;
	stringPTR = &str;

	std::string	&stringREF = str;

	std::cout << "&str      : '" << &str		<< "'" << std::endl;
	std::cout << "stringPTR : '" << stringPTR	<< "'" << std::endl;
	std::cout << "&stringREF: '" << &stringREF	<< "'" << std::endl;
	std::cout << "str       : '" << str			<< "'" << std::endl;
	std::cout << "*stringPTR: '" << *stringPTR	<< "'" << std::endl;
	std::cout << "stringREF : '" << stringREF	<< "'" << std::endl;
}
