/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:02:36 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/09 11:49:14 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_hexa(char c)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

void	ft_print_memory(void	*addr, unsigned int size)
{
	char	*str;
	int		i;

	i = size * 2;
	size *= 2;
	str = "";
	while (*str != '\0')
	{
		if ((*str < 32) || (*str > 126))
		{
			ft_putchar('\\');
			ft_put_hexa(*str);
		}
		else
			ft_putchar(*str);
		str++;
	}
}
