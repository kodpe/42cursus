/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:31:01 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/12 16:16:01 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *petittraindecaracteres)
{
	while (*petittraindecaracteres)
		write(1, &(*petittraindecaracteres++), 1);
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_print_args(int ac, char **av)
{
	while (ac-- > 1)
		ft_putstr(av[ac]);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i <= ac - 1)
	{
		j = i + 1;
		while (j <= ac - 1)
		{
			if (ft_strcmp(av[i], av[j]) < 0)
			{
				tmp = av[i];
				av[i] = av[j];
				av[j] = tmp;
			}
			j++;
		}
		i++;
	}
	ft_print_args(ac, av);
	return (0);
}
