/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:42:39 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/12/11 14:30:27 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static inline void	ft_bzero_bis(t_ulong *ptr, size_t len_64, size_t len_8)
{
	while (len_64--)
	{
		ptr[0] = 0;
		ptr[1] = 0;
		ptr[2] = 0;
		ptr[3] = 0;
		ptr[4] = 0;
		ptr[5] = 0;
		ptr[6] = 0;
		ptr[7] = 0;
		ptr += 8;
	}
	while (len_8--)
		*ptr++ = 0;
}

void	ft_bzero(void *s, size_t n)
{
	t_ulong	*long_ptr;
	int		align;

	align = n & 7;
	while (align--)
		*(char *)s++ = 0;
	long_ptr = (t_ulong *)s;
	if (n >= 8)
		ft_bzero_bis(long_ptr, n >> 6, (n & 63) >> 3);
}
