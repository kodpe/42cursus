/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 03:31:01 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/16 14:27:30 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& a, T& b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T&	min(const T& a, const T& b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
const T&	max(const T& a, const T& b)
{
	if (a > b)
		return a;
	return b;
}

#endif /* WHATEVER_HPP */
