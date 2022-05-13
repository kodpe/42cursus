/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:40:39 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/22 23:07:47 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_first_check(t_key *key, int	nbr_lines)
{
	char	ref[2];
	int		i;
	int		k;

	ref[0] = '0';
	ref[1] = '\0';
	i = 0;
	while (i < 10)
	{
		k = 0;
		while (k < nbr_lines)
		{
			if (ft_strcmp(key[k].num, ref) == 0)
				break ;
			k++;
		}
		if (k == nbr_lines)
			return (0);
		i++;
		ref[0] = (i + 48);
	}
	return (1);
}

int	ft_second_check(t_key *key, int	nbr_lines)
{
	char	ref[3];
	int		i;
	int		k;

	ref[0] = '1';
	ref[1] = '0';
	ref[2] = '\0';
	i = 0;
	while (i < 10)
	{
		k = 0;
		while (k < nbr_lines)
		{
			if (ft_strcmp(key[k].num, ref) == 0)
				break ;
			k++;
		}
		if (k == nbr_lines)
			return (0);
		i++;
		ref[1] = (i + 48);
	}
	return (1);
}

int	ft_third_check(t_key *key, int	nbr_lines)
{
	char	ref[3];
	int		i;
	int		k;

	ref[0] = '2';
	ref[1] = '0';
	ref[2] = '\0';
	i = 2;
	while (i < 10)
	{
		k = 0;
		while (k < nbr_lines)
		{
			if (ft_strcmp(key[k].num, ref) == 0)
				break ;
			k++;
		}
		if (k == nbr_lines)
			return (0);
		i++;
		ref[0] = (i + 48);
	}
	return (1);
}

void	ft_high_numbers_tab(char *tab, int n_zero)
{
	int	i;

	i = 1;
	tab[0] = '1';
	while (i <= n_zero)
	{
		tab[i] = '0';
		i++;
	}
	tab[i] = '\0';
}

int	ft_fourth_check(t_key *key, int nbr_lines)
{
	char	tab[38];
	int		i;
	int		k;

	i = 3;
	while (i < 38)
	{
		ft_high_numbers_tab(tab, i);
		k = 0;
		while (k < nbr_lines)
		{
			if (ft_strcmp(key[k].num, tab) == 0)
				break ;
			k++;
		}
		if (k == nbr_lines)
			return (0);
		i += 3;
	}
	return (1);
}
