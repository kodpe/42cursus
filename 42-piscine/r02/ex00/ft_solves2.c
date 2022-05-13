/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solves2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 23:25:57 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/22 23:36:45 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

/*
void	ft_precise1(t_key *key, int nbr_lines, char *nbr)
{
	int	i;

	i = 0;
	while (i <= nbr_lines)
	{
		if (key[i].num[0] == nbr[0] && key[i].num[1] == '\0')
		{
			ft_putstr(key[i].word);
			ft_putchar(' ');
			break ;
		}
		i++;
	}
}

void	ft_precise2(t_key *key, int nbr_lines, char *nbr, int precise)
{
	int	i;

	i = 0;
	while (i <= nbr_lines)
	{
		if (key[i].num[0] == nbr[0] && key[i].num[1] == '0')
		{
			ft_putstr(key[i].word);
			ft_putchar(' ');
			break ;
		}
		i++;
	}
	if (!(nbr[1] == '0'))
		ft_precise1(key, nbr_lines, nbr[1]);
}

void	ft_precise3(t_key *key, int nbr_lines, char *nbr, int precise)
{
	int	i;

	precise = 1;
	i = 0;
	ft_precise1(key, nbr_lines, nbr[0]);
	while (i <= nbr_lines)
	{
		if (key[i].num[0] == '1' && key[i].num[1] == '0'
			&& key[i].num[2] == '0'
			&& key[i].num[3] == '\0')
		{
			ft_putstr(key[i].word);
			ft_putchar(' ');
			break ;
		}
		i++;
	}
}
*/
