/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:34:30 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/09 12:41:07 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tx.h"

int	tx_atoi(const char *str, const char *msg)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += *str - 48;
		str++;
	}
	if (TX_VERBOSE)
		printf(" \033[32m OK\033[0m  tx_atoi(%s)->(%i)\n"\
			, msg, nbr * sign);
	return (nbr * sign);
}
