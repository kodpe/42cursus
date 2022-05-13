/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_operations_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 06:07:09 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 07:13:47 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * swap a and swap b at the same time.
 */
void	ss(t_two *s)
{
	ft_stack_swap_top(s->a);
	ft_stack_swap_top(s->b);
	print_op("ss");
}

/**
 * rotate a and rotate b at the same time.
 */
void	rr(int n, t_two *s)
{
	while (n > 0)
	{
		ft_stack_add_bottom(s->a, ft_stack_pop(s->a));
		ft_stack_add_bottom(s->b, ft_stack_pop(s->b));
		print_op("rr");
		n--;
	}
}

/**
 * reverse rotate a and reverse rotate b at the same time.
 */
void	rrr(int n, t_two *s)
{
	while (n > 0)
	{
		ft_stack_push(s->a, ft_stack_pop_bottom(s->a));
		ft_stack_push(s->b, ft_stack_pop_bottom(s->b));
		print_op("rrr");
		n--;
	}
}

/**
 * swap a then rotate a
 */
void	sa_ra(t_two *s)
{
	sa(s);
	ra(1, s);
}

/**
 * rotate a then swap a
 */
void	ra_sa(t_two *s)
{
	ra(1, s);
	sa(s);
}
