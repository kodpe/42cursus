/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 08:11:07 by amassy            #+#    #+#             */
/*   Updated: 2021/08/08 10:51:45 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_write_first_line(int	x)
{
	ft_putchar('A');
	if (x == 2)
		ft_putchar('C');
	if (x > 2)
	{
		x -= 2;
		while (x > 0)
		{
			ft_putchar('B');
			x--;
		}
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	ft_write_interior_line(int x)
{
	ft_putchar('B');
	if (x == 2)
		ft_putchar('B');
	if (x > 2)
	{
		x -= 2;
		while (x > 0)
		{
			ft_putchar(' ');
			x--;
		}
		ft_putchar('B');
	}
	ft_putchar('\n');
}

void	ft_write_last_line(int x)
{
	ft_putchar('C');
	if (x == 2)
		ft_putchar('A');
	if (x > 2)
	{
		x -= 2;
		while (x > 0)
		{
			ft_putchar('B');
			x--;
		}
		ft_putchar('A');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if ((x <= 0) || (y <= 0))
		return ;
	if (y == 1)
		ft_write_first_line(x);
	if (y == 2)
	{
		ft_write_first_line(x);
		ft_write_last_line(x);
	}
	if (y > 2)
	{
		ft_write_first_line(x);
		y -= 2;
		while (y > 0)
		{
			ft_write_interior_line(x);
			y--;
		}
		ft_write_last_line(x);
	}
}
