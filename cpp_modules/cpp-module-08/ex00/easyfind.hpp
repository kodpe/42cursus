/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:33:08 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/17 18:12:38 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& container, const int to_find)
{
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end())
		throw std::invalid_argument("not in container");
	return it;
}

#endif /* EASYFIND_HPP */
