/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:09:53 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/25 19:51:46 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_absolute(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

void	ft_put_ten_queens(char *tab)
{
	int	x;

	x = 0;
	while (x < 10)
	{
		ft_putchar(tab[x] + 48);
		x++;
	}
	ft_putchar('\n');
}

void	ft_recursive_queens(char *tab, int x, int *solutions)
{
	int	i;
	int	y;

	if (x == 10)
	{
		ft_put_ten_queens(tab);
		*solutions += 1;
		return ;
	}
	y = 0;
	while (y < 10)
	{
		i = 0;
		while (i < x && y != tab[i] && ft_absolute(tab[i] - y) != x - i)
			i++;
		if (i >= x)
		{
			tab[x] = y;
			ft_recursive_queens(tab, x + 1, solutions);
		}
		y++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	tab[10];
	int		solutions;

	solutions = 0;
	ft_recursive_queens(tab, 0, &solutions);
	return (solutions);
}
