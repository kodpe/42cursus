/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 01:06:21 by sloquet           #+#    #+#             */
/*   Updated: 2021/12/14 02:50:54 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# ifdef linux
#  define OS_PTR_NULL "(nil)"
#  define OS_PTR_NULL_SIZE 5
# else
#  define OS_PTR_NULL "0x0"
#  define OS_PTR_NULL_SIZE 3
# endif

int		ft_printf(const char *format, ...);
int		ft_putnbase(unsigned long nbr, const char *base, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_nbrlen(long nbr, int base);
int		ft_putnbr_fd(int n, int fd);

#endif
