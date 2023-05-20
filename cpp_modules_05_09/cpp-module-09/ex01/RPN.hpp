/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:20:02 by sloquet           #+#    #+#             */
/*   Updated: 2023/04/21 19:48:02 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>

#include <stack>
#include <list>

typedef std::stack<int, std::list<int> > t_stack;

class RPN
{
	public:
		RPN();
		RPN(std::string str);
		RPN(RPN const & raw);
		~RPN();
		RPN & operator=(RPN const & rhs);

	private:
		std::stack< int, std::list<int> >	_stack;
		void	show(void);
		int		is_token(const char c);
		int		top_pop(void);
		void	doop(const char c);
};

#endif /* RPN_HPP */
