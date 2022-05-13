/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:09:09 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/19 19:23:02 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //tmp
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		dest[i] = src[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_char_in_str(char c, char *str)
{
	while (*str)
		if (c == *str++)
			return (1);
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (ft_char_in_str(str[i], charset) == 1 && str[i])
			i++;
		if (str[i] == '\0')
			break ;
		while (ft_char_in_str(str[i], charset) == 0 && str[i])
			i++;
		count++;
	}
	return (count);
}

int	ft_get_next_str(char **split, char *str, char *charset)
{
	int	i;
	int	end;
	int	start;
	int	pos;

	pos = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		end = 0;
		while (ft_char_in_str(str[i], charset) == 1 && str[i])
			i++;
		start = i;
		while (ft_char_in_str(str[i], charset) == 0 && str[i])
			i++;
		end = i;
		split[pos] = malloc(sizeof(char) * (end - start + 1));
		if (split[pos] == NULL)
			return (0);
		ft_strcpy(split[pos], str, start, end);
		if (str[i] == '\0')
			break ;
		pos++;
	}
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	char	*tmp;
	int		wd_count;

	tmp = str;
	wd_count = ft_count_words(str, charset);
	split = malloc(sizeof(char *) * (wd_count + 1));
	if (split == NULL)
		return (0);
	if (ft_get_next_str(split, tmp, charset) == 0)
		return (0);
	split[wd_count] = NULL;
	return (split);
}
