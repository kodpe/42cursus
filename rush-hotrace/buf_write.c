/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 09:34:12 by sloquet           #+#    #+#             */
/*   Updated: 2021/12/12 12:29:14 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void	buf_write(t_buf *buf, const void *src, int n)
{
	const char	*tmp;

	tmp = src;
	if (buf->len + n >= BUFFER_SIZE2)
	{
		write(1, buf->buf, buf->len);
		write(1, tmp, n);
		buf->len = 0;
	}
	else
	{
		while (n--)
		{
			buf->buf[buf->len] = *tmp++;
			buf->len++;
		}
	}
}

void	found(t_buf *buf, const char *val)
{
	buf_write(buf, val, ft_strlen(val));
	buf_write(buf, "\n", 1);
}

void	notfound(t_buf *buf, const char *key, size_t n)
{
	buf_write(buf, key, n);
	buf_write(buf, ": Not found.\n", 13);
}
