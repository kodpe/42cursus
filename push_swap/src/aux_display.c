/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 07:03:22 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 07:20:16 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(char *operation)
{
	if (PUSHSWAP_MSG)
		ft_printf("%s ", operation);
	else
		ft_putsnl(operation);
}

void	show(t_two *s)
{
	if (!PUSHSWAP_MSG)
		return ;
	ft_stack_stats(s->a, "a");
	ft_stack_stats(s->b, "b");
}

void	summary_check(t_two *s, int good_len)
{
	if (!PUSHSWAP_MSG)
		return ;
	show(s);
	if (good_len == s->a->top + 1)
		ft_putstr("\e[0;32m A_SIZE OK  \e[0m");
	else
		ft_putstr("\e[0;31m A_SIZE KO  \e[0m");
	if (-1 == s->b->top)
		ft_putstr("\e[0;32m B_SIZE OK  \e[0m");
	else
		ft_putstr("\e[0;31m B_SIZE KO  \e[0m");
	if (ft_stack_ascs(s->a))
		ft_putstr("\e[0;32m *A ASC OK*  \e[0m");
	else if (ft_stack_des(s->a, 0))
		ft_putstr("\e[0;31m *A DES KO*  \e[0m");
	else
		ft_putstr("\e[0;31m *A NOT KO*  \e[0m");
}
