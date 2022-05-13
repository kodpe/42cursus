/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:51:05 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/23 13:58:38 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void	ft_show_tab(struct s_stock_str *par);

int main()
{
	char *lol[3];
	int i = 0;
	lol[0] = "baignoire";
	lol[1] = "brocoli";
	lol[2] = "une pintade";
	t_stock_str *res = ft_strs_to_tab(3, lol);
	while (res[i].str)
	{
		printf("%d, %s, %s\n", res[i].size, res[i].str, res[i].copy);
		i++;
	}
	ft_show_tab(res);
}
