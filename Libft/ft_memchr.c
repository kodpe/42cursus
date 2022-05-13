/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:12:27 by sloquet           #+#    #+#             */
/*   Updated: 2021/11/28 22:58:39 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memchr scans the initial n bytes of the memory
 * area pointed to by s for the first instance of c.  Both c and the
 * bytes of the memory area pointed to by s are interpreted as unsigned char.
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*u;
	size_t			i;

	u = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (u[i] == (unsigned char)c)
			return ((void *)&u[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

void	test_ft_memchr(void)
{
	char *s1 = "";
	char *s2 = "abcdefabcdef";
	char *s3 = "11111111111111111111";

	printf("Testing ft_memchr():\nTest1...");
	if (ft_memchr(s1, 'x', 0) == NULL)
		printf("passed.");
	else
		printf("FAILED.");
	printf("\nTest2...");
	if (ft_memchr(s2, 'y', 0) == NULL)
		printf("passed.");
	else
		printf("FAILED.");
	printf("\nTest3...");
	if ((char *)ft_memchr(s2, 'a', 1) - s2 == 0)
		printf("passed.");
	else
		printf("FAILED.");
	printf("\nTest4...");
	if (ft_memchr(s2, 'd', 2) == NULL)
		printf("passed.");
	else
		printf("FAILED.");
	printf("\nTest5...");
	if ((char *)ft_memchr(s2, 'd', 12) - s2 == 3)
		printf("passed.");
	else
		printf("FAILED.");
	printf("\nTest6...");
	if ((char *)ft_memchr(s2, 'f', 12) - s2 == 5)
		printf("passed.");
	else
		printf("FAILED.");
	printf("\nTest7...");
	if ((char *)ft_memchr(s3, '1', 20) - s3 == 0)
		printf("passed.");
	else
		printf("FAILED.");
	putchar('\n');
}

int	main(void)
{
	test_ft_memchr();
	return (0);
}
*/
