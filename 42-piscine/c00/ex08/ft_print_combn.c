/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:10:08 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/18 17:10:13 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_multiple_str(int n, char *str, int size)
{
	int	i;

	while (*str <= size)
	{
		if (*str != size)
			write(1, str, n + 2);
		else
			write(1, str, n);
		i = n;
		while (i--)
		{
			str[i]++;
			if (str[i] <= size + i)
				break ;
		}
		while (++i > 0 && i < n)
			str[i] = str[i - 1] + 1;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	char	str[11];
	int		size;

	if (n < 1 || n > 9)
		return ;
	*str = 48;
	i = 0;
	while (i < n)
	{
		i++;
		str[i] = str[i - 1] + 1;
	}
	str[n] = ',';
	str[n + 1] = ' ';
	size = 48 + 10 - n;
	ft_print_multiple_str(n, str, size);
}
