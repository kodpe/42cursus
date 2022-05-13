/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:51:03 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/21 06:18:15 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}
/*
#include <stdio.h>

int	ft_is_z(char *str) 
{
	while (*str)
	{
		if (*str == 'z')
			return (1);
		str++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	printf("nbr of str with z : %d", ft_count_if(av, ac, &ft_is_z));
	return (0);
}
*/
