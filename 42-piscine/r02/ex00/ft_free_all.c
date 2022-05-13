/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:05:49 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/22 22:19:02 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	ft_free_dict(char **dict, int nbr_lines)
{
	int	i;

	i = 0;
	while (i < nbr_lines + 2)
	{
		free(dict[i]);
		i++;
	}
}

void	ft_free_key(t_key *key, int nbr_lines)
{
	int	i;

	i = 0;
	while (i < nbr_lines + 1)
	{
		free(key[i].num);
		free(key[i].word);
		i++;
	}
}
