/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:14:13 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/15 22:48:52 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_check_av(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 31)
	{
		while (str[i] != '\0')
		{
			if (((i % 2 == 0) && (str[i] >= '1' && str[i] <= '4')) || \
					(i % 2 == 1 && str[i] == ' '))
				i++;
			else
				return (0);
		}
		return (1);
	}
	else
		return (0);
}

void	ft_get_tower(char *str, int tower[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 31)
	{
		tower[j] = str[i] - 48;
		j++;
		i += 2;
	}
}
