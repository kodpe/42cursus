/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 09:25:27 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/15 22:48:49 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	main(int ac, char **av)
{
	int	tab[4][4];
	int	tower[16];

	if (ac == 2)
	{
		if (ft_check_av(av[1]))
		{
			ft_get_tower(av[1], tower);
			ft_create_tab(tab);
			if (ft_make_tab(tab, 0, tower))
			{
				ft_show_tab(tab);
				return (0);
			}
			else
				ft_putstr("Error\n");
		}
		else
			ft_putstr("Error\n");
	}
	else
		ft_putstr("Error\n");
	return (0);
}
