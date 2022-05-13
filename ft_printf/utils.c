/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:06:53 by sloquet           #+#    #+#             */
/*   Updated: 2021/12/14 02:49:58 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_nbrlen(long nbr, int base)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	nbr;

	nbr = n;
	if (n >= 0)
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	return (ft_nbrlen(nbr, 10));
}
