/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:37:52 by sloquet           #+#    #+#             */
/*   Updated: 2021/11/28 23:57:29 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strchr returns a pointer to the first occurrence
 * of the character c in the string s.
 */

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}
/*
#include <stdio.h>
#include <string.h>

static int	ft_test(const char *s, const char c)
{
	return (strchr(s, c) == ft_strchr(s, c));
}

int	main(void)
{
	if (!ft_test("Unbreakable", 'U')
		|| !ft_test("Unbreakable", '\0'))
	{
		printf("KO: ft_strchr\n");
		return (1);
	}
	printf("OK: ft_strchr\n");
}
*/
