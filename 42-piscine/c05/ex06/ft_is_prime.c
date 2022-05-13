/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:08:40 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/17 12:12:19 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	k;

	if (nb == 2 || nb == 3)
		return (1);
	if (nb <= 1 || nb % 2 == 0 || nb % 3 == 0)
		return (0);
	k = 5;
	while (k * k <= nb && k < 46341)
	{
		if (nb % k == 0 || nb % (k + 2) == 0)
			return (0);
		k += 6;
	}
	return (1);
}
