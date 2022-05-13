/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_putnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:24:51 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/09 21:32:20 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base);

int main(void)
{
	char base[] = "0123456789";
	unsigned long c;

	ft_putnbr_base(22, base);
	printf("\n");
	ft_putnbr_base(-1, base);
	printf("\n");
}
