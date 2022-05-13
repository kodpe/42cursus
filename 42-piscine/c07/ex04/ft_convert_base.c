/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 09:05:58 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/21 06:17:05 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_rev_str(char *str);
int		ft_len_base(char *base);
int		ft_atoi_base(char *str, char *base);

char	*ft_itoa(int nb, int size, char *base)
{
	int				i;
	unsigned int	n;
	char			*n_base;

	i = 0;
	n_base = (char *)malloc(sizeof(char) * 34);
	if (n_base == NULL)
		return (0);
	if (nb < 0)
		n = nb * -1;
	else
		n = nb;
	if (n == 0)
		n_base[i++] = base[0];
	while (n > 0)
	{
		n_base[i++] = base[n % size];
		n /= size;
	}
	if (nb < 0)
		n_base[i++] = '-';
	n_base[i] = '\0';
	ft_rev_str(n_base);
	return (n_base);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n_int;
	char	*n_base;

	if (ft_len_base(base_from) == 1 || ft_len_base(base_to) == 1)
		return (NULL);
	n_int = ft_atoi_base(nbr, base_from);
	n_base = ft_itoa(n_int, ft_len_base(base_to), base_to);
	return (n_base);
}
