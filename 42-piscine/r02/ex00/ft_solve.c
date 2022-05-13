/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:35:21 by nle-bret          #+#    #+#             */
/*   Updated: 2021/08/22 23:36:24 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

/*
void	ft_fonction(int nbr_lines, int dimension, t_key *key)
{
	int	i;

	i = 0;
	while (i <= nbr_lines)
	{
		if (key[i].num[dimension * 3 + 2] == '\0')
			ft_putstr(key[i].word);
		ft_putchar(' ');
		i++;
	}
}
void	ft_recursive(t_key *key, char *nbr, int nbr_lines, int parameter[2])
{
	int	dimension;
	int	precise;

	dimension = parameter[0];
	precise = parameter[1];
	if (precise == 1)
		ft_precise1(key, nbr_lines, nbr[0]);
	if (precise == 2)
		ft_precise2(key, nbr_lines, nbr, precise);
	if (precise == 0)
	{
		ft_precise3(key, nbr_lines, nbr, precise);
		dimension--;
	}
	while (dimension > 0)
	{
		if (dimension == 2)
			ft_fonction(nbr_lines, dimension, key);
		dimension--;
	}
}

void	ft_solve(t_key *key, char *nbr, int nbr_lines)
{
	int	len;
	int	parameter[2];

	len = ft_strlen(nbr);
	parameter[0] = len / 3;
	parameter[1] = len % 3;
	ft_recursive(key, nbr, nbr_lines, parameter);
}
*/
