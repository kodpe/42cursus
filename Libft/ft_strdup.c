/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:04:09 by sloquet           #+#    #+#             */
/*   Updated: 2021/11/29 01:12:07 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The strdup() function returns a pointer to a new string which is
 * a duplicate of the string s.  Memory for the new string is
 * obtained with malloc(3), and can be freed with free(3).
 */

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!new)
		return (NULL);
	return (ft_strcpy(new, src));
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int	ft_test(const char *string)
{
	char	*std_str;
	char	*ft_str;
	int		result;

	std_str = strdup(string);
	ft_str = ft_strdup(string);
	result = strcmp(std_str, ft_str);
	free(std_str);
	free(ft_str);
	return (result);
}

int	main(void)
{
	if (ft_test("Unbreakable")
		|| ft_test(""))
	{
		printf("KO: ft_strdup");
		return (1);
	}
	printf("OK: ft_strdup");
}
*/
