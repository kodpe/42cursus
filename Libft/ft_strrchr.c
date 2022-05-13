/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:02:13 by sloquet           #+#    #+#             */
/*   Updated: 2021/11/28 23:59:22 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strrchr returns a pointer to the last occurrence
 * of the character c in the string s.
 */

char	*ft_strrchr(const char *s, int c)
{
	char	*r;

	r = NULL;
	if (!c)
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)c)
			r = (char *)s;
		s++;
	}
	return (r);
}
/*
#include <stdio.h>
#include <string.h>

static int	ft_test(const char *s, const char c)
{
	return (strrchr(s, c) == ft_strrchr(s, c));
}

int	main(void)
{
	if (!ft_test("Unbreakable", 'U')
		|| !ft_test("Unbreakable", '\0')
		|| !ft_test("", '\0')
		|| !ft_test("Un\0breakable", '\0')
		|| !ft_test("Un\0breakable", 'r'))
	{
		printf("KO: ft_strrchr\n");
		return (1);
	}
	printf("OK: ft_strrchr\n");
}
*/
