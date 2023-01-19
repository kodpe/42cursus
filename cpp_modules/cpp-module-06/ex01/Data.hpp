/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:52:38 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/13 21:10:40 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <stdint.h>
#include <string>

typedef struct	s_Data
{
	char			c;
	char			c2;
	int				i;	
	double			d;
	std::string		s;
}	Data;

uintptr_t	serialize(Data *ptr);
Data*		deserialize(uintptr_t raw);

#endif /* DATA_HPP */
