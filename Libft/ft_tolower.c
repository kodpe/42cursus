/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:16:43 by sloquet           #+#    #+#             */
/*   Updated: 2021/11/28 22:20:04 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * If c is an uppercase letter, ft_tolower returns its lowercase
 * equivalent, if a lowercase representation exists in the current
 * locale.  Otherwise, it returns c.
 */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	ft_test(int c)
{
	return (tolower(c) == ft_tolower(c));
}

int	main(void)
{
	int		i;

	i = -1000;
	while (i <= 1000)
	{
		if (!ft_test(i))
		{
			printf("KO: ft_tolower\n");
			return (1);
		}
		i++;
	}
	printf("OK: ft_tolower\n");
}
*/
