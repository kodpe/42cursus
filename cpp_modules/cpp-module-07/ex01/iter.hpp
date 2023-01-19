/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:04:49 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/15 04:38:27 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T>
void	iter(T *tab, size_t n, void (*func)(const T&))
{
	for (size_t i = 0; i < n; i++)
		func(tab[i]);
}

#endif /* ITER_HPP */
