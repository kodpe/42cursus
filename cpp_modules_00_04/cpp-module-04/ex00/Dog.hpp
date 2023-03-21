/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:47:40 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/04 01:48:55 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog ();
		Dog (const Dog &other);
   	   ~Dog ();
		Dog & operator=(const Dog &other);

		void	makeSound(void) const;
};

#endif /* DOG_CLASS_HPP */
