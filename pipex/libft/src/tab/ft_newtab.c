/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 09:33:42 by sloquet           #+#    #+#             */
/*   Updated: 2022/05/25 13:59:01 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tab.h"

int	*ft_newtab(const int size)
{
	int	*tab;
	int	i;

	tab = (int *)malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = -2;
		i++;
	}
	return (tab);
}
