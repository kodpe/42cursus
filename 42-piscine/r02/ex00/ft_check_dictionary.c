/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dictionary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:39:48 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/22 23:09:22 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	ft_clean_key(char *str)
{
	int	i;
	int	index_key;
	int	index_dpt;
	int	len_key;

	i = 0;
	index_key = ft_get_index_key(str);
	len_key = ft_get_len_nbr(str, index_key);
	while (str[index_key])
	{
		str[i] = str[index_key];
		index_key++;
		i++;
	}
	str[i] = '\0';
	index_dpt = ft_get_index_dpt(str);
	i = len_key;
	while (str[index_dpt])
	{
		str[i] = str[index_dpt];
		index_dpt++;
		i++;
	}
	str[i] = '\0';
}

int	ft_check_line(char *str)
{
	int	index_dpt;
	int	index_key;

	index_dpt = ft_get_index_dpt(str);
	index_key = ft_get_index_key(str);
	if (index_dpt == -1 || index_key == -1)
		return (0);
	if (ft_check_value(str, index_dpt) == -1)
		return (0);
	ft_clean_key(str);
	return (1);
}

int	ft_check_dictionary(char **dict)
{
	int	i;

	i = 0;
	while (dict[i] != NULL)
	{
		if (!ft_check_line(dict[i]))
			return (0);
		i++;
	}
	return (1);
}
