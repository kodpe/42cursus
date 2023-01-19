/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 01:34:02 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/08 17:30:38 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

#include <iostream>
#include <string>
#include "log.hpp"

class Brain
{
	public:
		Brain();
		Brain(const Brain &other);
   	   ~Brain ();
		Brain & operator=(const Brain &other);

		void setIdea(int i, const std::string& new_idea);
		const std::string getIdea(int i) const;

	private:
		static const int	brain_size = 100;
		std::string			ideas[brain_size];
};

#endif /* BRAIN_CLASS_HPP */
