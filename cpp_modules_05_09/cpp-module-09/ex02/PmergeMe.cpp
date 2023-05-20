/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:44:44 by sloquet           #+#    #+#             */
/*   Updated: 2023/04/24 22:39:48 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	show(std::vector<int> vec, const char* title)
{
	std::cout << title << " ";

	std::vector<int>::iterator	it;
	int	n = 0;
	for (it = vec.begin(); it != vec.end(); ++it)
	{
		if (n == 4 && vec.size() > 5)
		{
			std::cout << "[...]";
			break ;
		}
		std::cout << *it << " ";
		++n;
	}
	std::cout << std::endl;
}

void	show(std::deque<int> deq, const char* title)
{
	std::cout << title << " ";

	std::deque<int>::iterator	it;
	int	n = 0;
	for (it = deq.begin(); it != deq.end(); ++it)
	{
		if (n == 4 && deq.size() > 5)
		{
			std::cout << "[...]";
			break ;
		}
		std::cout << *it << " ";
		++n;
	}
	std::cout << std::endl;
}

// 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, ...
size_t	jacobsthal_nb(int n)
{
	if (n == 0 || n == 1)
		return n;
	return	jacobsthal_nb(n - 1) + 2 * jacobsthal_nb(n - 2);
}

int	sc_strtoll(const char *str, long long *nb, char next)
{
	char	*endptr;

	if (str == NULL || !isdigit(*str))
		return -1;
	*nb = strtoll(str, &endptr, 10);
	if ((*nb == 0 && endptr == str) || errno == ERANGE || *endptr != next)
		return -1;
	if (*nb < 1 || *nb > 2147483647)
		return -1;
	return 0;
}

void	show_elapsed_time(std::clock_t start, std::clock_t end, std::string title, int size)
{
    std::cout 	<< std::fixed << std::setprecision(5)
				<< "Time to process a range of " << size
				<< " elements with std::" << title << " : "
				<< 1000.0 * (end - start) / CLOCKS_PER_SEC << " ms\n";
}

/******************************************************************************/

PmergeMe::PmergeMe() :
	_size(0), _vec(), _vec_pair(), _deq(), _deq_pair()
{}

PmergeMe::PmergeMe(char **av) :
	_size(0), _vec(), _vec_pair(), _deq(), _deq_pair()
{
	long long	nb;

	for (int i = 0; av[i]; ++i)
	{
		if (sc_strtoll(av[i], &nb, 0))
			throw std::invalid_argument("Error: bad input: '" + std::string(av[i]) + "'");
		if (std::find(_vec.begin(), _vec.end(), nb) != _vec.end())
			throw std::invalid_argument("Error: duplicate: '" + std::string(av[i]) + "'");
		_vec.push_back(nb);
		_deq.push_back(nb);
	}
	_size = _vec.size();
	_vec_cmp = _vec;
	_deq_cmp = _deq;

	std::clock_t	start;
	std::clock_t	end;

	show(_vec, "Before:");
	start = std::clock();
	vec_fjmi_sort();
	end = std::clock();
	show(_vec, "After :");
	show_elapsed_time(start, end, "vector", _size);
	vec_checker();

	// show(_deq, "Before:");
	start = std::clock();
	deq_fjmi_sort();
	end = std::clock();
	// show(_deq, "After :");
	show_elapsed_time(start, end, "deque ", _size);
	deq_checker();
}

PmergeMe::PmergeMe(PmergeMe const & other)
{
	*this = other;
}

PmergeMe::~PmergeMe()
{
	_size = 0;
	_vec.clear();
	_deq.clear();
	_vec_cmp.clear();
	_deq_cmp.clear();
	_vec_pair.clear();
	_deq_pair.clear();
}

PmergeMe & PmergeMe::operator=(PmergeMe const & other)
{
	if (this != &other)
	{
		_size = other._size;
		_vec = other._vec;
		_deq = other._deq;
		_vec_cmp = other._vec_cmp;
		_deq_cmp = other._deq_cmp;
		_vec_pair = other._vec_pair;
		_deq_pair = other._deq_pair;
	}
	return *this;
}
