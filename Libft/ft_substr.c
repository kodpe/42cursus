/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:37:27 by sloquet           #+#    #+#             */
/*   Updated: 2021/11/29 01:51:40 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates (with malloc(3)) and returns a substring
 * from the string ’s’.
 * The substring begins at index ’start’ and is of
 * maximum size ’len’.
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
/*
#include <stdio.h>
#include <string.h>

static int	ft_test(char *string, unsigned int start, size_t length, char *ref)
{
	char	*output;
	int		result;

	output = ft_substr(string, start, length);
	result = strcmp(output, ref);
	free(output);
	return (result);
}

int	main(void)
{
	if (ft_test("", 0, 0, "")
		|| ft_test("ft_substr", 0, 0, "")
		|| ft_test("ft_substr", 0, 1, "f")
		|| ft_test("ft_substr", 1, 0, "")
		|| ft_test("ft_substr", 1, 1, "t")
		|| ft_test("ft_substr", 0, 9, "ft_substr")
		|| ft_test("ft\0strsub", 0, 2, "ft"))
	{
		printf("KO: ft_substr\n");
		return (1);
	}
	printf("OK: ft_substr\n");
	return (0);
}
*/
