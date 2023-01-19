/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:21:54 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/28 09:07:17 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

#define STR_USAGE "usage: sed <filename> <old_string> <new_string>"

void	log(const char *str)
{
	std::cerr << str << std::endl;
}

void	ft_replace(std::string &str, std::string search, std::string replace)
{
	size_t	len_search = search.length();
	size_t	len_replace = replace.length();
	size_t	i = 0;

	if (len_search == 0)
		return ;
	while (1)
	{
		i = str.find(search, i);
		if (i == std::string::npos)
			break ;
		str.erase(i, len_search);
		str.insert(i, replace);
		i += len_replace;
	}
}

int main(int ac, char **av)
{
	if (ac != 4) {
		log(STR_USAGE);
		return 1;
	}
	std::string	filename = av[1];
	std::ifstream	input(filename.c_str());
	if (!input) {
		log("erreur input file");
		return 2;
	}
	filename		+= ".replace";
	std::ofstream	output(filename.c_str());
	if (!output) {
		log("erreur output file");
		return 3;
	}

	std::string	buffer = "";
	std::string	line = "";

	while (std::getline(input, line)) {
		buffer += line;
		if (!input.eof())
			buffer += "\n";
	}

	ft_replace(buffer, av[2], av[3]);
	output << buffer;

	input.close();
	output.close();
	return 0;
}
