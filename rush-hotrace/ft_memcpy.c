/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:45:07 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/12/11 11:13:00 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static inline void	ft_copy_128(t_ulong *ptr_dest, t_ulong *ptr_src,
				size_t len_128)
{
	while (len_128--)
	{
		ptr_dest[0] = ptr_src[0];
		ptr_dest[1] = ptr_src[1];
		ptr_dest[2] = ptr_src[2];
		ptr_dest[3] = ptr_src[3];
		ptr_dest[4] = ptr_src[4];
		ptr_dest[5] = ptr_src[5];
		ptr_dest[6] = ptr_src[6];
		ptr_dest[7] = ptr_src[7];
		ptr_dest[8] = ptr_src[8];
		ptr_dest[9] = ptr_src[9];
		ptr_dest[10] = ptr_src[10];
		ptr_dest[11] = ptr_src[11];
		ptr_dest[12] = ptr_src[12];
		ptr_dest[13] = ptr_src[13];
		ptr_dest[14] = ptr_src[14];
		ptr_dest[15] = ptr_src[15];
		ptr_dest += 16;
		ptr_src += 16;
	}
}

static inline void	ft_copy_64(t_ulong **ptr_dest, t_ulong **ptr_src,
			size_t len_64)
{
	register t_ulong	*ptr1;
	register t_ulong	*ptr2;

	ptr1 = *ptr_dest;
	ptr2 = *ptr_src;
	while (len_64--)
	{
		ptr1[0] = ptr2[0];
		ptr1[1] = ptr2[1];
		ptr1[2] = ptr2[2];
		ptr1[3] = ptr2[3];
		ptr1[4] = ptr2[4];
		ptr1[5] = ptr2[5];
		ptr1[6] = ptr2[6];
		ptr1[7] = ptr2[7];
		ptr1 += 8;
		ptr2 += 8;
	}
	*ptr_dest = ptr1;
	*ptr_src = ptr2;
}

static inline void	ft_copy_32(t_ulong **ptr_dest, t_ulong **ptr_src,
					size_t len_32)
{
	register t_ulong	*ptr1;
	register t_ulong	*ptr2;

	ptr1 = *ptr_dest;
	ptr2 = *ptr_src;
	while (len_32--)
	{
		ptr1[0] = ptr2[0];
		ptr1[1] = ptr2[1];
		ptr1[2] = ptr2[2];
		ptr1[3] = ptr2[3];
		ptr1 += 4;
		ptr2 += 4;
	}
	*ptr_dest = ptr1;
	*ptr_src = ptr2;
}

static inline void	ft_copy_16(t_ulong **ptr_dest, t_ulong **ptr_src,
				size_t len_16)
{
	register t_ulong	*ptr1;
	register t_ulong	*ptr2;

	ptr1 = *ptr_dest;
	ptr2 = *ptr_src;
	while (len_16--)
	{
		ptr1[0] = ptr2[0];
		ptr1[1] = ptr2[1];
		ptr1 += 2;
		ptr2 += 2;
	}
	*ptr_dest = ptr1;
	*ptr_src = ptr2;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	t_ulong			*ptr_dest;
	t_ulong			*ptr_src;
	register void	*ret;
	register int	align;

	ret = dest;
	align = n & 7;
	while (align--)
		*(char *)dest++ = *(char *)src++;
	ptr_dest = (t_ulong *)dest;
	ptr_src = (t_ulong *)src;
	ft_copy_128(ptr_dest, ptr_src, n >> 7);
	ptr_dest += (n >> 7) << 4;
	ptr_src += (n >> 7) << 4;
	n &= 127;
	ft_copy_64(&ptr_dest, &ptr_src, n >> 6);
	n &= 63;
	ft_copy_32(&ptr_dest, &ptr_src, n >> 5);
	n &= 31;
	ft_copy_16(&ptr_dest, &ptr_src, n >> 4);
	n &= 15;
	n >>= 3;
	while (n--)
		*ptr_dest++ = *ptr_src++;
	return (ret);
}
