/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 03:21:20 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/24 21:23:06 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define DEFAULT "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << DEFAULT << std::endl;
		return 0;
	}
	for (int n = 1; n < ac; n++)
	{
		std::string	str(av[n]);

		for (int i = 0; str[i]; i++)
			str[i] = std::toupper(str[i]);
		std::cout << str;
	}
	std::cout << std::endl;
}
