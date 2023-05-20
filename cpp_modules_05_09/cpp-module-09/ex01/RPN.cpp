/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:42:19 by sloquet           #+#    #+#             */
/*   Updated: 2023/04/25 11:21:33 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(): _stack()
{}

RPN::RPN(RPN const & other)
{
	*this = other;
}

RPN::~RPN()
{}

RPN & RPN::operator=(RPN const & other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

void	RPN::show(void)
{
	while (_stack.size())
	{
		std::cout << _stack.top() << " ";
		_stack.pop();
	}
	std::cout << std::endl;
}

int		RPN::is_token(const char c)
{
	return c == '+' || c == '-' || c == '/' || c == '*';
}

int		RPN::top_pop(void)
{
	int	n = _stack.top();
	_stack.pop();
	return n;
}

void	RPN::doop(const char token)
{
	if (_stack.size() < 2)
		throw std::invalid_argument("Error");
	int	a = top_pop();
	int	b = top_pop();
	switch (token)
	{
		case '+':
			_stack.push(b + a);
			break;
		case '-':
			_stack.push(b - a);
			break;
		case '*':
			_stack.push(b * a);
			break;
		case '/':
			if (a == 0)
				throw std::invalid_argument("Error");
			_stack.push(b / a);
	}
}

RPN::RPN(std::string str): _stack()
{
	std::string::iterator	it;

	for (it = str.begin(); it != str.end(); ++it)
	{
		if (isdigit(*it))
			_stack.push(*it - 48);
		else if (*it == '-' && isdigit(*(it + 1)))
		{
			_stack.push(-(*(it + 1) - 48));
			++it;
		}
		else if (is_token(*it))
			doop(*it);
		else
			throw std::invalid_argument("Error");
		++it;
		if (it == str.end())
			break ;
		if (*it != ' ')
			throw std::invalid_argument("Error");
	}
	if (_stack.size() != 1 || str[str.size() - 1] == ' ')
		throw std::invalid_argument("Error");
	show();
}
