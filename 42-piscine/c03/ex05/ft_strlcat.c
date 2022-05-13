/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:05:48 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/11 17:09:52 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	resultat;

	i = 0;
	k = 0;
	resultat = 0;
	while (dest[i] != '\0')
		i++;
	while (src[resultat] != '\0')
		resultat++;
	if (size <= i)
		resultat += size;
	else
		resultat += i;
	while (src[k] != '\0' && (i + 1) < size)
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (resultat);
}
