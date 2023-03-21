/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:22:51 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/08 18:03:04 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

# include <iostream>
# include <string>
# include "log.hpp"

class Animal
{
	public:
		Animal ();
		Animal (const Animal &other);
   	    virtual ~Animal ();
		Animal & operator=(const Animal &other);

		std::string const & getType(void) const;

		virtual void		makeSound(void) const = 0;

	protected:
		std::string	type;
};

#endif /* ANIMAL_CLASS_HPP */
