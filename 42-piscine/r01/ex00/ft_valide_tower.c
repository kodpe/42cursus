/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valide_tower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 21:02:55 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/15 23:35:15 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_check_col_hb(int tab[4][4], int tower[16], int i)
{
	int	y;
	int	g;
	int	cmp;

	cmp = 1;
	y = 0;
	g = tab[i][0];
	while (y < 4)
	{
		if (g < tab[i][y])
		{
			g = tab[i][y];
			cmp++;
		}
		y++;
	}
	if (cmp == tower[i])
		return (1);
	else
		return (0);
}

int	ft_check_col_bh(int tab[4][4], int tower[16], int i)
{
	int	y;
	int	g;
	int	cmp;

	cmp = 1;
	y = 3;
	i = i - 4;
	g = tab[i][3];
	while (y >= 0)
	{
		if (g < tab[i][y])
		{
			g = tab[i][y];
			cmp++;
		}
		y--;
	}	
	if (cmp == tower[i + 4])
	{
		return (1);
	}
	else
		return (0);
}

int	ft_check_line_gd(int tab[4][4], int tower[16], int i)
{
	int	x;
	int	g;
	int	cmp;

	cmp = 1;
	x = 0;
	i = i - 8;
	g = tab[0][i];
	while (x < 4)
	{
		if (g < tab[x][i])
		{
			g = tab[x][i];
			cmp++;
		}
		x++;
	}
	if (cmp == tower[i + 8])
		return (1);
	else
		return (0);
}

int	ft_check_line_dg(int tab[4][4], int tower[16], int i)
{
	int	x;
	int	g;
	int	cmp;

	cmp = 1;
	x = 3;
	i = i - 12;
	g = tab[3][i];
	while (x >= 0)
	{
		if (g < tab[x][i])
		{
			g = tab[x][i];
			cmp++;
		}
		x--;
	}
	if (cmp == tower[i + 12])
		return (1);
	else
		return (0);
}

int	ft_ok_tower(int val, int tab[4][4], int pos, int tower[16])
{
	int	x;
	int	y;

	val = 123;
	x = pos / 4;
	y = pos % 4;
	if (x == 3)
	{
		if (!(ft_check_line_gd(tab, tower, y + 8)))
			return (0);
		if (!(ft_check_line_dg(tab, tower, y + 12)))
			return (0);
	}
	if (y == 3)
	{
		if (!(ft_check_col_hb(tab, tower, x)))
			return (0);
		if (!(ft_check_col_bh(tab, tower, x + 4)))
			return (0);
	}
	return (1);
}
