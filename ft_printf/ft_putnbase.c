/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:02:52 by sloquet           #+#    #+#             */
/*   Updated: 2021/12/14 03:01:56 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

static int	ft_nbrlen_ul(unsigned long nbr, unsigned int base)
{
	int	i;

	i = 1;
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

static int	ft_check_base(const char *base)
{
	if (ft_strlen(base) < 2)
		return (0);
	if (ft_strchr(base, '+') || ft_strchr(base, '-'))
		return (0);
	while (*base)
	{
		if (ft_strchr(base + 1, *base))
			return (0);
		base++;
	}
	return (1);
}

int	ft_putnbase(unsigned long nbr, const char *base, int fd)
{
	unsigned long	n;
	int				size;

	if (!ft_check_base(base))
		return (-1);
	n = (unsigned long)nbr;
	size = (unsigned long)ft_strlen(base);
	if (n >= ft_strlen(base))
		ft_putnbase(n / size, base, fd);
	write(fd, &base[n % size], 1);
	return (ft_nbrlen_ul(nbr, size));
}
