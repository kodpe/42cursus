/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:40:16 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/24 17:23:29 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*parasol;
	int	i;

	if (length < 1)
		return (NULL);
	parasol = malloc(sizeof(int) * length);
	if (parasol == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		parasol[i] = f(tab[i]);
		i++;
	}
	return (parasol);
}
/*
#include <stdio.h>

int	ft_up(int nb) 
{
	return (nb + 1);
}

int	main(void)
{
	int	tab[5] = {1110, -223, +7776, 443, 888888887};
	int	*t = malloc(sizeof(int) * 5);

	t = ft_map(tab, 5, &ft_up);
	for (int i = 0; i < 5; i++) 
		printf("[%d]", t[i]);
	return (0);
}

gcc -Wall -Wextra -Werror -g3 -fsanitize=address
*/
