/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_deq_dbg.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:20:32 by sloquet           #+#    #+#             */
/*   Updated: 2023/04/25 11:22:17 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	is_unique(std::deque<int> deq)
{
	std::deque<int>::iterator	it;
	std::deque<int>::iterator	it2;

	for(it = deq.begin(); it != deq.end() - 1; ++it)
	{
		for (it2 = it + 1; it2 != deq.end(); ++it2)
		{
			if (*it == *it2)
				return false;
		}
	}
	return true;
}

bool	is_asc_sort(std::deque<int> deq)
{
	std::deque<int>::iterator	it;

	if (deq.size() == 1)
		return true;

	for (it = deq.begin() + 1; it != deq.end(); ++it)
		if (*(it - 1) > *it)
			return false;
	return true;
}

void	PmergeMe::deq_checker(void)
{
#ifndef DEBUG
	return ;
#endif
	(is_asc_sort(_deq)) ? std::cout << CL_GREEN : std::cout << CL_RED;
	std::cout << " [ is_asc_sort ] ";

	(_size == _deq.size()) ? std::cout << CL_GREEN : std::cout << CL_RED;
	std::cout << " [ size " << _deq.size() << " ] ";

	std::sort(_deq.begin(), _deq.end());
	(std::equal(_deq.begin(), _deq.end(), _deq.begin())) ? std::cout << CL_GREEN : std::cout << CL_RED;
	std::cout << " [ is_equal ] ";

	(is_unique(_deq)) ? std::cout << CL_GREEN : std::cout << CL_RED;
	std::cout << " [ is_unique ]\n" << CL_RESET;
}

/*
void	dbgv(std::deque<int> vec, const char* title)
{
	std::cout << title << " : ";
	std::deque<int>::iterator	it;
	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	show_pair(std::deque< std::pair<int,int> >::iterator p)
{
	std::cout << "p->first  : " << p->first << "   ";
	std::cout << "p->second : " << p->second << "\n";
}

void	PmergeMe::show_pp(void)
{
	std::cout << "===" << "\n";
	std::deque< std::pair<int,int> >::iterator	p;
	for (p = _deq.begin(); p != _deq.end(); ++p)
		show_pair(p);
	std::cout << "size : " << _deq.size() << "\n";
	std::cout << "===" << "\n\n";
}

*/
