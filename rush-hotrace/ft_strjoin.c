/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:47:17 by ggiquiau          #+#    #+#             */
/*   Updated: 2021/12/11 11:10:27 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	n_s1;
	size_t	n_s2;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	n_s1 = ft_strlen(s1);
	n_s2 = ft_strlen(s2);
	str = (char *)malloc(n_s1 + n_s2 + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, n_s1 * sizeof(char));
	ft_memcpy(str + n_s1, s2, (n_s2 + 1) * sizeof(char));
	return (str);
}
