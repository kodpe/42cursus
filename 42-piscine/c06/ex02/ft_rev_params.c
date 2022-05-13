/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:25:06 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/12 09:29:25 by sloquet          ###   ########.fr       */
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
	if (ac)
	{
		while (ac > 1)
		{
			ft_putstr(av[--ac]);
			ft_poudlard('\n');
		}
	}
	return (0);
}
