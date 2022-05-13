/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:24:05 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/19 20:02:51 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (dest[i])
		i++;
	while (src[k])
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_get_size(int size, char **strs, char *sep)
{
	char	*cat;
	int		len_total;
	int		len_sep;
	int		i;

	i = 0;
	len_total = 0;
	while (strs[i] && i < size)
	{
		len_total += ft_strlen(strs[i]);
		i++;
	}
	len_sep = (ft_strlen(sep) * (i - 1));
	len_total += len_sep;
	cat = malloc((sizeof(char) * len_total + 1));
	cat[0] = '\0';
	return (cat);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*cat;
	int		i;

	if (size < 1)
	{
		cat = malloc(1);
		cat[0] = 0;
		return (cat);
	}
	cat = ft_get_size(size, strs, sep);
	i = -1;
	while (strs[++i] && i < size)
	{
		cat = ft_strcat(cat, strs[i]);
		if (i < size - 1)
			cat = ft_strcat(cat, sep);
	}
	return (cat);
}
