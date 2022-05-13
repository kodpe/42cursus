/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 10:57:37 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/08 10:58:21 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_write_line(int x, char first_char, char interio_char, char last_char)
{
	ft_putchar(first_char);
	if (x == 2)
		ft_putchar(last_char);
	if (x > 2)
	{
		x -= 2;
		while (x > 0)
		{
			ft_putchar(interio_char);
			x--;
		}
		ft_putchar(last_char);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if ((x <= 0) || (y <= 0))
		return ;
	if (y == 1)
		ft_write_line(x, 'A', 'B', 'A');
	if (y == 2)
	{
		ft_write_line(x, 'A', 'B', 'A');
		ft_write_line(x, 'C', 'B', 'C');
	}
	if (y > 2)
	{
		ft_write_line(x, 'A', 'B', 'A');
		y -= 2;
		while (y > 0)
		{
			ft_write_line(x, 'B', ' ', 'B');
			y--;
		}
		ft_write_line(x, 'C', 'B', 'C');
	}
}
