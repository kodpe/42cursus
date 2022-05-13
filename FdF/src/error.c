/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 04:25:32 by sloquet           #+#    #+#             */
/*   Updated: 2022/04/09 04:22:21 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// 1703-1741
void	error_line(const t_line *a)
{
	if (FDF_DEBUG)
		ft_printf("ERR bad line (%d,%d)(%d,%d)\n", a->x0, a->y0, a->x1, a->y1);
}

// 1703-1809
int	error_getnbr(int fd, int n)
{
	ft_printf("ERR get_numbers()\n");
	if (0 > fd)
	{
		perror("get_numbers()");
		return (n);
	}
	ft_close_gnl(fd);
	close(fd);
	return (n);
}

// 1903-2004
int	error_exit(int code, char *msg)
{
	ft_printf("\033[0;33mERR %d : %s\033[0m\n", code, msg);
	exit (code);
}
