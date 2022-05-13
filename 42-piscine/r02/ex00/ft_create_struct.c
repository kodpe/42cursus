/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 23:07:19 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/22 23:13:17 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

t_key	*ft_declare_struct(int nbr_lines)
{
	t_key	*key;

	key = malloc(sizeof(t_key) * (nbr_lines + 1));
	if (key == NULL)
		return (0);
	key[nbr_lines].num = 0;
	key[nbr_lines].word = 0;
	return (key);
}

t_key	*ft_putonstruct(char **dict, t_key *key)
{
	int	i;
	int	j;
	int	pos_init;

	i = 0;
	while (dict[i])
	{
		j = 0;
		while (dict[i][j])
		{
			if (dict[i][j] == ':')
			{
				pos_init = 0;
				key[i].num = ft_strxdup(dict[i], pos_init, j);
				pos_init = j + 1;
				key[i].word = ft_strxdup(dict[i], pos_init, ft_strlen(dict[i]));
			}
			j++;
		}
		i++;
	}
	return (key);
}

int	ft_check_double(t_key *key, int	nbr_lines)
{
	int	i;
	int	k;

	i = 0;
	while (i < nbr_lines - 1)
	{
		k = i + 1;
		while (k < nbr_lines)
		{
			if (ft_strcmp(key[i].num, key[k].num) == 0)
			{
				if (ft_strcmp(key[i].word, key[k].word) != 0)
					return (0);
			}
			k++;
		}
		i++;
	}
	return (1);
}

int	ft_check_keys(t_key *key, int nbr_lines)
{
	if (!(ft_check_double(key, nbr_lines)))
		return (0);
	if (!(ft_first_check(key, nbr_lines)))
		return (0);
	if (!(ft_second_check(key, nbr_lines)))
		return (0);
	if (!(ft_third_check(key, nbr_lines)))
		return (0);
	if (!(ft_fourth_check(key, nbr_lines)))
		return (0);
	return (1);
}
