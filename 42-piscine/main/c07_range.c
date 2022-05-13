/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_range.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:58:12 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/18 09:01:39 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	*ft_range(int min, int max);

int	main(void)
{
	char	*ptr = NULL;
	int		*tab;
	int		i;

	tab = ft_range(-12, -3);
	//tab = ft_range(10, 1);
	printf("%p\n", tab);
	printf("%p\n", ptr);
	for (i = 0; i < 40; i++)
		printf("[%d]", tab[i]);
	return (0);
}
