/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_deq.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:21:38 by sloquet           #+#    #+#             */
/*   Updated: 2023/04/24 15:10:59 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::deq_make_sorted_pair(void)
{
	std::deque<int>::iterator	it;

	for (it = _deq.begin() + 1; it != _deq.end(); ++it)
	{
		_deq_pair.push_back(std::make_pair(*(it - 1), *it));
		if (++it == _deq.end())
			break ;
	}

	std::deque< std::pair<int,int> >::iterator	p;

	for (p = _deq_pair.begin(); p != _deq_pair.end(); ++p)
	{
		if (p->first < p->second)
			std::swap(p->first, p->second);
	}
	std::sort(_deq_pair.begin(), _deq_pair.end());
}

int	PmergeMe::deq_get_len(void)
{
	std::deque<int>::iterator	it;
	int	len = 0;
	for (it = _deq.begin(); *it != _dp->first; ++it)
		len++;
	return	len;
}

void	PmergeMe::deq_bin_insert(int len, int to_insert)
{
	int		m, L = 0;

	if (len == 0)
		_deq.insert(_deq.begin(), to_insert);

	while (L < len)
	{
		m = (L + len) / 2;
		if (len - L == 1)
		{
			if (_deq[m] > to_insert)
				_deq.insert(_deq.begin() + m, to_insert);
			else
				_deq.insert(_deq.begin() + m + 1, to_insert);
			break ;
		}
		if (_deq[m] <= to_insert)
			L = m;
		else
			len = m;
	}
}

void	PmergeMe::deq_jacobsthal_opti(void)
{
	size_t prevj = 1;
	size_t j = 1;
	size_t k = 2;

	if (_deq_pair.size() == 1)
		return ;
	while (1)
	{
		j = jacobsthal_nb(k);
		// std::cout << "jacob " << std::setw(2) << k << ":" << std::setw(6) << j << " ";
		if (j >= _deq_pair.size())
			break;
		// std::cout << "insert [" << std::setw(4) << j - 1 << "]\n";
		_dp = _deq_pair.begin() + j - 1;
		deq_bin_insert(deq_get_len(), _dp->second);

		if (j != 1)
		{
			// std::cout << "jacob " << std::setw(2) << k << ":" << std::setw(6) << j << " ";
			// std::cout << "insert [" << prevj << ";" << j - 2 << "]\n";
			for (_dp = _deq_pair.begin() + prevj; _dp != _deq_pair.begin() + j - 1; ++_dp)
				deq_bin_insert(deq_get_len(), _dp->second);
		}
		prevj = j;
		k++;
	}
	// std::cout << "insert [" << prevj << ";" << _deq_pair.size() - 1 << "] FINAL\n";
	for (_dp = _deq_pair.begin() + prevj; _dp != _deq_pair.end(); ++_dp)
		deq_bin_insert(deq_get_len(), _dp->second);
}

void	PmergeMe::deq_fjmi_sort(void)
{
	int	odd_value(0);

	if (_deq.size() < 2)
		return ;
	if (_size % 2 == 1)
	{
		odd_value = _deq.back();
		_deq.pop_back();
	}

	deq_make_sorted_pair();

	_deq.clear();
	for (_dp = _deq_pair.begin(); _dp != _deq_pair.end(); ++_dp)
			_deq.push_back(_dp->first);

	deq_jacobsthal_opti();

	if (_deq_pair.size() == 1)
		_deq.insert(_deq.begin(), _deq_pair.begin()->second);

	if (_size % 2 == 1)
		deq_bin_insert(_deq.size(), odd_value);
}
