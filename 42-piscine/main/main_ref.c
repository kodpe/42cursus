/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:06:01 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/09 11:49:48 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while ((src[i] != '\0') && (i < size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

int	main(void)
{
	//char			dest[] = {0};
	//char			ad[] = {0};

	char			dest[64] = "Hello world";
	char			ad[64] = "Hello world";
	unsigned int	n;

	n = 20;
	printf("%s$", dest);
	printf("\n\n");

	printf("me %u$", ft_strlcpy(dest, "Fromage", n));
	printf("\n");
	printf("%s$", dest);
	printf("\n\n");

	printf("ok %lu$", strlcpy(ad, "Fromage", n));
	printf("\n");
	printf("%s$", ad);
	printf("\n");
}
