/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:46:40 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/04 00:46:45 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat ();
		Cat (const Cat &other);
   	   ~Cat ();
		Cat & operator=(const Cat &other);

		void	makeSound(void) const;
};

#endif /* CAT_CLASS_HPP */
