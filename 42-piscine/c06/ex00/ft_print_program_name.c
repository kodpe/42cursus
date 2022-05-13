/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:00:39 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/12 09:12:34 by sloquet          ###   ########.fr       */
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
		ft_putstr(av[0]);
		ft_poudlard('\n');
	}
	return (0);
}
