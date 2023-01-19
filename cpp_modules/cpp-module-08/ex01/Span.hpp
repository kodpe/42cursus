/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:29:38 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/18 02:04:42 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP

#include <iostream>
#include <ctime>
#include <vector>		// insert erase push_back
#include <algorithm>	// max_element min_element find generate sort
#include <iterator> 	// ostreambuf_iterator

#define DEBUG 0
#define COLOR "\033[34m"
#define RESET "\033[0m"

class Span
{
	public:
		class SpanIsFull : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class SpanTooSmall : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		Span();
		Span(unsigned int N);
		Span(const Span &other);
   	   ~Span();
		Span & operator=(const Span &other);

		void	addNumber(int nb);

		void	addRange(const std::vector<int>::const_iterator& begin,
							const std::vector<int>::const_iterator& end);
		void	fill(void);

		size_t	shortestSpan(void) const;
		size_t	longestSpan(void) const;

		void	displaySpan(void) const;

	private:
		std::vector<int>	_vec;
		unsigned int		_N;

		void	displayVector(const std::vector<int>& v, const char *name) const;
};

#endif /* SPAN_CLASS_HPP */
