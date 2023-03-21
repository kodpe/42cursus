/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:43:07 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/08 15:47:57 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define VERBOSE	1
#define COLOR	1

#define RESET	"\x1b[0m"
#define RED		"\x1b[31m"	// error
#define GREEN	"\x1b[32m" 	// creation
#define YELLOW	"\x1b[33m"	// special
#define BLUE	"\x1b[34m"	// title
#define MAGENTA	"\x1b[35m"	// destruction
#define CYAN	"\x1b[36m"
#define WHITE	"\x1b[37m"

#define LOG_NEWLINE		if (VERBOSE) {std::cout << std::endl;}

#define LOG(msg, color)	if (VERBOSE && COLOR) \
							{std::cout << color << msg << RESET << std::endl;} \
						else if (VERBOSE) \
							{std::cout << msg << std::endl;}

#define LOGN(msg, color) if (VERBOSE && COLOR) \
							{std::cout << color << msg << RESET;} \
						else if (VERBOSE) \
							{std::cout << msg;}

#define LOG_TITLE(msg)	LOG_NEWLINE \
						LOGN(" ===== * ", BLUE) \
						LOGN(msg, BLUE) \
						LOG(" * ===== ", BLUE)

#define LOG_DEFAULT_CONSTRUCTOR(name)	LOGN(name, GREEN); LOG(" default constructor", GREEN);
#define LOG_COMMON_CONSTRUCTOR(name)	LOGN(name, GREEN); LOG(" constructor", GREEN);
#define LOG_COPY_CONSTRUCTOR(name)		LOGN(name, YELLOW); LOG(" copy constructor", YELLOW);
#define LOG_OPERATOR_ASSIGN(name) 		LOGN(name, YELLOW); LOG(" assignation operator", YELLOW);
#define LOG_DESTRUCTOR(name)			LOGN(name, MAGENTA); LOG(" destructor", MAGENTA);
