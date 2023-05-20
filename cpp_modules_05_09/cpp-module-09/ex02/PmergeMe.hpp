/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:17:52 by sloquet           #+#    #+#             */
/*   Updated: 2023/04/25 11:27:37 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cerrno>

#include <vector>
#include <deque>

#define CL_GREEN	"\x1b[32m"
#define CL_RED		"\x1b[31m"
#define CL_RESET	"\x1b[0m"

//#define DEBUG

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(char **av);
		PmergeMe(PmergeMe const & other);
		~PmergeMe();
		PmergeMe & operator=(PmergeMe const & other);

	private:
		size_t				_size;

		std::vector<int>	_vec;
		std::vector<int>	_vec_cmp;

		std::vector< std::pair<int,int> >			_vec_pair;
		std::vector< std::pair<int,int> >::iterator	_vp;

		void	vec_make_sorted_pair(void);
		int		vec_get_len(void);
		void	vec_bin_insert(int len, int to_insert);
		void	vec_jacobsthal_opti(void);
		void	vec_fjmi_sort(void);
		void	vec_checker(void);

		std::deque<int>	_deq;
		std::deque<int>	_deq_cmp;

		std::deque< std::pair<int,int> >			_deq_pair;
		std::deque< std::pair<int,int> >::iterator	_dp;

		void	deq_make_sorted_pair(void);
		int		deq_get_len(void);
		void	deq_bin_insert(int len, int to_insert);
		void	deq_jacobsthal_opti(void);
		void	deq_fjmi_sort(void);
		void	deq_checker(void);
};

size_t	jacobsthal_nb(int n);
int		sc_strtoll(const char *str, long long *nb, char next);

#endif /* PMERGE_ME_HPP */
