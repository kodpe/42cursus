/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:24:05 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/19 17:05:29 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> //tmp

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (dest[k] != '\0')
		k++;
	while (src[i] != '\0')
	{
		dest[k] = src[i];
		k++;
		i++;
	}
	dest[k] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_get_size(char **strs, int nb_str)
{
	int	size;

	size = 0;
	while (--nb_str > 0)
		size += ft_strlen(strs[nb_str]);
	return (size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*cat;
	int		size_all;

	if (size == 0)
	{
		cat = malloc(sizeof(char));
		cat[0] = 0;
		return (cat);
	}
	size_all = ft_get_size(strs, size) + (ft_strlen(sep) * (size - 1));
	cat = malloc((size_all + 1) * sizeof(char));
	i = 0;
	while (i < size - 1)
		cat = ft_strcat(ft_strcat(cat, strs[i++]), sep);
	cat = ft_strcat(cat, strs[i++]);
	return (cat);
}

int	main(int ac, char **av)
{
	//int		i;
	char	*str;
//	ac = 0;
	str = ft_strjoin(ac - 1, &av[1], "123");
	printf("ac = %d size_all = %d\n\n", ac, ft_get_size(av, ac));
	/*
	   for (i = 1; i < ac; i++)
	   printf("%s\n", av[i]);
	   */
	//str = NULL;
	printf("--------------------\n");
	printf("s %s\n", str);
	printf("d %d\n", str[0]);
	printf("p %p\n", str);
	return (0);
}
