/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_vec.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:21:38 by sloquet           #+#    #+#             */
/*   Updated: 2023/04/24 15:10:56 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::vec_make_sorted_pair(void)
{
	std::vector<int>::iterator	it;

	for (it = _vec.begin() + 1; it != _vec.end(); ++it)
	{
		_vec_pair.push_back(std::make_pair(*(it - 1), *it));
		if (++it == _vec.end())
			break ;
	}

	std::vector< std::pair<int,int> >::iterator	p;

	for (p = _vec_pair.begin(); p != _vec_pair.end(); ++p)
	{
		if (p->first < p->second)
			std::swap(p->first, p->second);
	}
	std::sort(_vec_pair.begin(), _vec_pair.end());
}

int	PmergeMe::vec_get_len(void)
{
	std::vector<int>::iterator	it;
	int	len = 0;
	for (it = _vec.begin(); *it != _vp->first; ++it)
		len++;
	return	len;
}

void	PmergeMe::vec_bin_insert(int len, int to_insert)
{
	int		m, L = 0;

	if (len == 0)
		_vec.insert(_vec.begin(), to_insert);

	while (L < len)
	{
		m = (L + len) / 2;
		if (len - L == 1)
		{
			if (_vec[m] > to_insert)
				_vec.insert(_vec.begin() + m, to_insert);
			else
				_vec.insert(_vec.begin() + m + 1, to_insert);
			break ;
		}
		if (_vec[m] <= to_insert)
			L = m;
		else
			len = m;
	}
}

void	PmergeMe::vec_jacobsthal_opti(void)
{
	size_t prevj = 1;
	size_t j = 1;
	size_t k = 2;

	if (_vec_pair.size() == 1)
		return ;
	while (1)
	{
		j = jacobsthal_nb(k);
		// std::cout << "jacob " << std::setw(2) << k << ":" << std::setw(6) << j << " ";
		if (j >= _vec_pair.size())
			break;
		// std::cout << "insert [" << std::setw(4) << j - 1 << "]\n";
		_vp = _vec_pair.begin() + j - 1;
		vec_bin_insert(vec_get_len(), _vp->second);

		if (j != 1)
		{
			// std::cout << "jacob " << std::setw(2) << k << ":" << std::setw(6) << j << " ";
			// std::cout << "insert [" << prevj << ";" << j - 2 << "]\n";
			for (_vp = _vec_pair.begin() + prevj; _vp != _vec_pair.begin() + j - 1; ++_vp)
				vec_bin_insert(vec_get_len(), _vp->second);
		}
		prevj = j;
		k++;
	}
	// std::cout << "insert [" << prevj << ";" << _vec_pair.size() - 1 << "] FINAL\n";
	for (_vp = _vec_pair.begin() + prevj; _vp != _vec_pair.end(); ++_vp)
		vec_bin_insert(vec_get_len(), _vp->second);
}

void	PmergeMe::vec_fjmi_sort(void)
{
	int	odd_value(0);

	if (_vec.size() < 2)
		return ;
	if (_size % 2 == 1)
	{
		odd_value = _vec.back();
		_vec.pop_back();
	}

	vec_make_sorted_pair();

	_vec.clear();
	for (_vp = _vec_pair.begin(); _vp != _vec_pair.end(); ++_vp)
			_vec.push_back(_vp->first);

	vec_jacobsthal_opti();

	if (_vec_pair.size() == 1)
		_vec.insert(_vec.begin(), _vec_pair.begin()->second);

	if (_size % 2 == 1)
		vec_bin_insert(_vec.size(), odd_value);
}
