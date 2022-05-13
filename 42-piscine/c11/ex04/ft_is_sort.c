/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:58:14 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/24 17:30:37 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sbig(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_bsmall(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ft_sbig(tab, length, f) || ft_bsmall(tab, length, f))
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	ft_diff(int	a, int b) 
{
	return (a - b);
}

int	main(void)
{
	int	n[5] = {1110, -223, 7776, 443, 8887};
	int	m[5] = {-10, -9, -9, -9, -9};
	int	y[5] = {-345, -22, +7, 44, 888};
	int	t[5] = {190, 22, 7, 4, -1};

	printf("sort n0 : %d\n", ft_is_sort(n, 5, &ft_diff));
	printf("sort m1 : %d\n", ft_is_sort(m, 5, &ft_diff));
	printf("sort y1 : %d\n", ft_is_sort(y, 5, &ft_diff));
	printf("sort t1 : %d\n", ft_is_sort(t, 5, &ft_diff));

	int tab1[] = {1,2,3,4,5};
    int tab2[] = {5,4,3,2,1};
    int tab3[] = {-1,-1,-1,-1,-100};
    int tab4[] = {-10,-9,-9,-9,-9};
    int tab5[] = {-1,5,4,3,2,-1};
    int tab6[] = {44,32,66,1,2};
    int tab7[] = {4, 4, 4, 4, 1};

	printf("sort tab1 : %d\n", ft_is_sort(tab1, 5, &ft_diff));
	printf("sort tab2 : %d\n", ft_is_sort(tab2, 5, &ft_diff));
	printf("sort tab3 : %d\n", ft_is_sort(tab3, 5, &ft_diff));
	printf("sort tab4 : %d\n", ft_is_sort(tab4, 5, &ft_diff));
	printf("sort tab5 : %d\n", ft_is_sort(tab5, 5, &ft_diff));
	printf("sort tab6 : %d\n", ft_is_sort(tab6, 5, &ft_diff));
	printf("sort tab7 : %d\n", ft_is_sort(tab7, 5, &ft_diff));
	return (0);
}*/
