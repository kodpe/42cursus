/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:51:32 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/09 18:59:12 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(int c)
{
	return ((c == 32) || (c >= 9 && c <= 13));
}

int	ft_atoi(char *str)
{
	int		sign;
	int		nbr;

	sign = 1;
	nbr = 0;
	while (ft_is_space(*str) == 1)
		str++;
	while ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		nbr = (*str - 48) + (nbr * 10);
		str++;
	}
	return (nbr * sign);
}
