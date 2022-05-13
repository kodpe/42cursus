/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:37:07 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/11 15:58:07 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				k;

	i = 0;
	k = 0;
	while (dest[k] != '\0')
		k++;
	while ((src[i] != '\0') && (i < nb))
	{
		dest[k] = src[i];
		k++;
		i++;
	}
	dest[k] = '\0';
	return (dest);
}
