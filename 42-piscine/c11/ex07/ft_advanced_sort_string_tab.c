/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:55:13 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/26 00:54:19 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tablen(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int		i;
	int		k;
	int		len;
	char	*tmp;

	len = ft_tablen(tab);
	i = 0;
	while (i < len)
	{
		k = 0;
		while (k < len - 1)
		{
			if (cmp(tab[k], tab[k + 1]) > 0)
			{
				tmp = tab[k];
				tab[k] = tab[k + 1];
				tab[k + 1] = tmp;
			}
			k++;
		}
		i++;
	}
}
/*
#include <unistd.h>

void	ft_putstr(char *petittraindecaracteres)
{
	while (*petittraindecaracteres)
		write(1, &(*petittraindecaracteres++), 1);
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	av[ac] = 0;
	ft_advanced_sort_string_tab(av, &ft_strcmp);
	while (ac-- > 0)
		ft_putstr(av[ac]);
	return (0);
}
*/
