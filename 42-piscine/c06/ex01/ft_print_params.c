/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:13:19 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/12 09:17:25 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_poudlard(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *petittraindecaracteres)
{
	while (*petittraindecaracteres)
		ft_poudlard(*petittraindecaracteres++);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac)
	{
		i = 1;
		while (i < ac)
		{
			ft_putstr(av[i]);
			ft_poudlard('\n');
			i++;
		}
	}
	return (0);
}
