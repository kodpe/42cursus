/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:55:35 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/18 01:52:11 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template < class T, class Container = std::deque<T> >
class MutantStack : public std::stack< T, Container >
{
	public:
		MutantStack() : std::stack<T, Container>() {};
		MutantStack(const MutantStack &other) : std::stack<T, Container>() {
			*this = other;
		}
   	   ~MutantStack() {};
		MutantStack & operator=(const MutantStack &other)
		{
			if (this != &other)
				this->c = other.c;
			return *this;
		}

		typedef typename Container::iterator iterator;

		iterator	begin() { return this->c.begin(); }

		iterator	end() { return this->c.end(); }
};

#endif /* MUTANTSTACK_HPP */
