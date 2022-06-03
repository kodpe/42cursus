/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:54:40 by sloquet           #+#    #+#             */
/*   Updated: 2022/06/03 18:27:02 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (len--)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = 0;
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(s) + (ft_strlen(s2) + 1)));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	free(s);
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

int	get_index(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
