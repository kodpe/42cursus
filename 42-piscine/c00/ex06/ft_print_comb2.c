/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:29:57 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/04 21:02:52 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	ft_putchar(48 + n / 10);
	ft_putchar(48 + n % 10);
}

void	ft_print_comb2(void)
{
	int	a;	
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putnbr(a);
			ft_putchar(' ');
			ft_putnbr(b);
			if (a != 98)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
