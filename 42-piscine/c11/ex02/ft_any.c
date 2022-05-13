/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:47:57 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/24 19:18:44 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int(*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
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
	ac = 0;
	printf("z : %d", ft_any(av, &ft_is_z));
	return (0);
}*/
