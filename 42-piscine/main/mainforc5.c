/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:39:06 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/16 19:42:14 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_is_prime(int nb);

int	main(void)
{
	int	n;

	n = 2147483647;
	printf("ft is prime %d > %d\n", n, ft_is_prime(n));
	return (0);
}
