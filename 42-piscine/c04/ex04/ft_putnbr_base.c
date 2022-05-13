/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:35:21 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/10 09:35:40 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check_same_value(char *base)
{
	int	i;
	int	r;

	i = 0;
	while (base[i] != '\0')
	{
		r = 0;
		while (base[r] != '\0')
		{
			if ((base[i] == base[r]) && (i != r))
				return (1);
			r++;
		}
		i++;
	}
	return (0);
}

int	ft_check_base(char *base)
{
	int	i;

	if (ft_strlen(base) <= 1)
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if ((base[i] == 43) || (base[i] == 45))
			return (1);
		i++;
	}
	if (ft_check_same_value(base) == 1)
		return (1);
	return (0);
}

void	ft_put_base_recu(unsigned int n, char *base, unsigned int size)
{
	char	z;

	if (n >= size)
		ft_put_base_recu(n / size, base, size);
	z = base[n % size];
	write(1, &z, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;
	int				i;

	i = 0;
	if (ft_check_base(base) == 1)
		return ;
	if (nbr < 0)
	{
		n = (nbr * (-1));
		write(1, "-", 1);
	}
	else
		n = nbr;
	ft_put_base_recu(n, base, ft_strlen(base));
}
