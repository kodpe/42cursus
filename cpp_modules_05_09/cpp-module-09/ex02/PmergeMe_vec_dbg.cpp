/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_vec_dbg.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:21:38 by sloquet           #+#    #+#             */
/*   Updated: 2023/04/25 11:22:17 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	is_unique(std::vector<int> vec)
{
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	it2;

	for(it = vec.begin(); it != vec.end() - 1; ++it)
	{
		for (it2 = it + 1; it2 != vec.end(); ++it2)
		{
			if (*it == *it2)
				return false;
		}
	}
	return true;
}

bool	is_asc_sort(std::vector<int> vec)
{
	std::vector<int>::iterator	it;

	if (vec.size() == 1)
		return true;

	for (it = vec.begin() + 1; it != vec.end(); ++it)
		if (*(it - 1) > *it)
			return false;
	return true;
}

void	PmergeMe::vec_checker(void)
{
#ifndef DEBUG
	return ;
#endif
	(is_asc_sort(_vec)) ? std::cout << CL_GREEN : std::cout << CL_RED;
	std::cout << " [ is_asc_sort ] ";

	(_size == _vec.size()) ? std::cout << CL_GREEN : std::cout << CL_RED;
	std::cout << " [ size " << _vec.size() << " ] ";

	std::sort(_vec_cmp.begin(), _vec_cmp.end());
	(std::equal(_vec.begin(), _vec.end(), _vec_cmp.begin())) ? std::cout << CL_GREEN : std::cout << CL_RED;
	std::cout << " [ is_equal ] ";

	(is_unique(_vec)) ? std::cout << CL_GREEN : std::cout << CL_RED;
	std::cout << " [ is_unique ]\n" << CL_RESET;
}

/*
void	dbgv(std::vector<int> vec, const char* title)
{
	std::cout << title << " : ";
	std::vector<int>::iterator	it;
	for (it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	show_pair(std::vector< std::pair<int,int> >::iterator p)
{
	std::cout << "p->first  : " << p->first << "   ";
	std::cout << "p->second : " << p->second << "\n";
}

void	PmergeMe::show_pp(void)
{
	std::cout << "===" << "\n";
	std::vector< std::pair<int,int> >::iterator	p;
	for (p = _vec_pair.begin(); p != _vec_pair.end(); ++p)
		show_pair(p);
	std::cout << "size : " << _vec_pair.size() << "\n";
	std::cout << "===" << "\n\n";
}

*/
