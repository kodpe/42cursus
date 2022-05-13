/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:05:59 by sloquet           #+#    #+#             */
/*   Updated: 2021/12/14 03:01:38 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_ptr(unsigned long ptr, int fd)
{
	if (!ptr)
	{
		ft_putstr_fd(OS_PTR_NULL, fd);
		return (OS_PTR_NULL_SIZE);
	}
	ft_putstr_fd("0x", fd);
	return (2 + ft_putnbase(ptr, "0123456789abcdef", fd));
}

static int	print_str(char *s, int fd)
{
	if (!s)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(s, fd);
	return ((int)ft_strlen(s));
}

static int	what_conv(char c, va_list *p, int fd)
{
	if (c == 's')
		return (print_str(va_arg(*p, char *), fd));
	else if (c == 'p')
		return (print_ptr(va_arg(*p, unsigned long), fd));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(*p, int), fd));
	else if (c == 'u')
		return (ft_putnbase(va_arg(*p, unsigned int), "0123456789", fd));
	else if (c == 'x')
		return (ft_putnbase(va_arg(*p, unsigned int), "0123456789abcdef", fd));
	else if (c == 'X')
		return (ft_putnbase(va_arg(*p, unsigned int), "0123456789ABCDEF", fd));
	else if (c == 'c')
		ft_putchar_fd(va_arg(*p, int), fd);
	else
		ft_putchar_fd(c, fd);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		i;
	int		nbytes;
	int		fd;

	fd = 1;
	i = 0;
	nbytes = 0;
	va_start(params, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			nbytes += what_conv(format[i + 1], &params, 1);
			i++;
		}
		else
		{
			write(fd, &format[i], 1);
			nbytes++;
		}
		i++;
	}
	va_end(params);
	return (nbytes);
}
