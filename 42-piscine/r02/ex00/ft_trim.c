/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:56:55 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/22 23:15:09 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	trim_before_point(char *dict)
{
	int	k;
	int	p;
	int	begin;

	k = 0;
	while (dict[k])
	{
		while (dict[k] >= '0' && dict[k] <= '9')
			k++;
		p = k;
		begin = k + 1;
		while (dict[k] == ' ')
			k++;
		while (dict[k])
		{
			dict[p] = dict[k];
			p++;
			k++;
		}
		dict[p] = '\0';
	}
	return (begin);
}

int	trim_after_point(char *dict, int begin)
{
	int	k;
	int	p;

	k = begin;
	p = begin;
	while (dict[k])
	{
		while (dict[k] == ' ')
			k++;
		begin = k;
		while (dict[k] >= 32 && dict[k] <= 126)
		{
			dict[p] = dict[k];
			k++;
			p++;
		}
		dict[p] = '\0';
	}
	return (begin - 1);
}

void	trim_end(char *dict)
{
	int	i;

	i = ft_strlen(dict) - 1;
	while (dict[i] == ' ')
		i--;
	dict[i + 1] = '\0';
}

void	ft_trim(char **dict)
{
	int	i;
	int	begin;

	i = 0;
	while (dict[i])
	{
		begin = trim_before_point(dict[i]);
		begin = trim_after_point(dict[i], begin);
		trim_end(dict[i]);
		i++;
	}
}
