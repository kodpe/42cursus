/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:00:00 by sloquet           #+#    #+#             */
/*   Updated: 2021/11/28 22:50:08 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memcpy copies n bytes from memory area src to
 * memory area dst. The memory areas must not overlap.
 */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	tmp = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*tmp++ = *s++;
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
char src[] = "The cow jumped over the moon.";
char dest[100];
ft_memcpy(dest, src, strlen(src) + 1);
printf("cpy str is %s\n", dest);

int tab[] = {10, 20, 30, 40, 50};
int n = sizeof(tab) / sizeof(tab[0]);
int idest[n];
ft_memcpy(idest, tab, sizeof(tab));
printf("cpy array is ");
for (int i = 0; i < n; i++)
        printf("%d ", idest[i]);
    printf("\n");
    return (0);
}
*/
