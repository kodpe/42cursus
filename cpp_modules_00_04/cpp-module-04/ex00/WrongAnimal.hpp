/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:22:51 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/08 15:33:34 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP

#include <iostream>
#include <string>
# include "log.hpp"

class WrongAnimal
{
	public:
		WrongAnimal ();
		WrongAnimal (const WrongAnimal &other);
   	    ~WrongAnimal ();
		WrongAnimal & operator=(const WrongAnimal &other);

		std::string const &	getType(void) const;
		void	makeSound(void) const;

	protected:
		std::string	type;

};

#endif /* WRONGANIMAL_CLASS_HPP */
