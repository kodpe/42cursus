/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 11:47:07 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/15 23:27:26 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	ft_create_tab(int tab[4][4])
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			tab[x][y] = 0;
			x++;
		}
		y++;
	}
}

void	ft_show_tab(int tab[4][4])
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			ft_putchar(tab[x][y] + 48);
			if (x < 3)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int	ft_abs_on_axes(int val, int tab[4][4], int line, int column)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < 4)
	{
		if (tab[line][y] == val)
			return (0);
		y++;
	}
	while (x < 4)
	{
		if (tab[x][column] == val)
			return (0);
		x++;
	}
	return (1);
}

// recursive function: fill the tab with uniaue val and visible tower checking
int	ft_make_tab(int tab[4][4], int pos, int tower[16])
{
	int	val;

	val = 1;
	if (pos == 4 * 4)
		return (1);
	if (tab[pos / 4][pos % 4] != 0)
		return (ft_make_tab(tab, pos + 1, tower));
	while (val <= 4)
	{
		if (ft_abs_on_axes(val, tab, pos / 4, pos % 4))
		{
			tab[pos / 4][pos % 4] = val;
			if (ft_ok_tower(val, tab, pos, tower))
			{
				if (ft_make_tab(tab, pos + 1, tower))
					return (1);
			}
		}
		val++;
	}
	tab[pos / 4][pos % 4] = 0;
	return (0);
}
