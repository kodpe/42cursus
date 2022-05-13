/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:09:23 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/26 13:40:21 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_do_op(char op, int a, int b)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
		return (a / b);
	if (op == '%')
		return (a % b);
	return (0);
}

int	ft_check_operator(char *op)
{
	if (*op == '-' || *op == '+' || *op == '/' || *op == '*' || *op == '%')
		op++;
	if (*op == 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	res;

	res = 0;
	if (ac != 4)
		return (0);
	if (ft_check_operator(av[2]))
	{
		if (av[2][0] == '%' && ft_atoi(av[3]) == 0)
			ft_putstr("Stop : modulo by zero\n");
		else if (av[2][0] == '/' && ft_atoi(av[3]) == 0)
			ft_putstr("Stop : division by zero\n");
		else
		{
			ft_putnbr(ft_do_op(av[2][0], ft_atoi(av[1]), ft_atoi(av[3])));
			ft_putchar('\n');
		}
	}
	else
		ft_putstr("0\n");
	return (0);
}
