/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:25:12 by sloquet           #+#    #+#             */
/*   Updated: 2022/12/28 09:48:43sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define COLOR	1
#define RED		if(COLOR){std::cout <<"\033[31m";}
#define GREEN	if(COLOR){std::cout <<"\033[32m";}
#define YELLOW	if(COLOR){std::cout <<"\033[33m";}
#define BLUE	if(COLOR){std::cout <<"\033[34m";}
#define PURPLE	if(COLOR){std::cout <<"\033[35m";}
#define CYAN	if(COLOR){std::cout <<"\033[36m";}
#define RESET	if(COLOR){std::cout <<"\033[0m";}

#define STR_DEBUG "I love having extra bacon for my\
7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"

#define STR_INFO "I cannot believe adding extra bacon costs more money. \
You didn’t putenough bacon in my burger ! If you did, I wouldn’t be asking for more !"

#define STR_WARNING "I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month."

#define STR_ERROR "This is unacceptable ! I want to speak to the manager now."

#define STR_UNKNOWN "[ Probably complaining about insignificant problems ] "

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	BLUE
	std::cout	<< "[ DEBUG ] " << std::endl << STR_DEBUG << std::endl;
	std::cout	<< std::endl;
	RESET
}

void	Harl::info(void)
{
	GREEN
	std::cout	<< "[ INFO  ] " << std::endl << STR_INFO << std::endl;
	std::cout	<< std::endl;
	RESET
}

void	Harl::warning(void)
{
	YELLOW
	std::cout	<< "[WARNING] " << std::endl << STR_WARNING << std:: endl;
	std::cout	<< std::endl;
	RESET
}

void	Harl::error(void)
{
	RED
	std::cout	<< "[ ERROR ] " << std::endl << STR_ERROR << std::endl;
	std::cout	<< std::endl;
	RESET
}

typedef void(Harl::*ptr_func)(void);

void	Harl::complain(std::string level)
{
	std::string	msgtype[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	i;
	for (i = 0; i < 4; i++)
	{
		if (level == msgtype[i])
			break ;
	}
	switch (i)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break ;
		default:
			std::cout	<< STR_UNKNOWN << std::endl << std::endl;
	}
}
