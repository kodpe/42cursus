/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_for_dictionary.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:33:05 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/22 23:14:34 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_get_index_dpt(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ':')
		i++;
	if (str[i] && str[i] == ':')
		return (i);
	return (-1);
}

int	ft_get_index_key(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] && str[i] == '+')
		i++;
	if (str[i] && ((str[i] >= '0') && (str[i] <= '9')))
		return (i);
	return (-1);
}

int	ft_get_len_nbr(char *str, int i)
{
	int	len;

	len = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		i++;
		len++;
	}
	return (len);
}

int	ft_check_value(char *str, int pos)
{
	int	i;

	i = pos + 1;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
			return (-1);
		i++;
	}
	i = pos + 1;
	while (str[i])
	{
		if (str[i] >= 33 && str[i] <= 126)
			return (1);
		i++;
	}
	return (-1);
}
