/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:46:40 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/04 00:53:19 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat ();
		WrongCat (const WrongCat &other);
   	   ~WrongCat ();
		WrongCat & operator=(const WrongCat &other);

		void	makeSound(void) const;
};

#endif /* WRONGCAT_CLASS_HPP */
