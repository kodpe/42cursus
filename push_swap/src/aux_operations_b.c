/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_operations_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 06:06:59 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 07:13:29 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * swap b - swap the first 2 elements at the top of stack b.
 */
void	sb(t_two *s)
{
	ft_stack_swap_top(s->b);
	print_op("sb");
}

/**
 * push b - take the first element at the top of a and put it at the top of b.
 */
void	pb(int n, t_two *s)
{
	while (n > 0)
	{
		ft_stack_push(s->b, ft_stack_pop(s->a));
		print_op("pb");
		n--;
	}
}

/**
 * rotate b - shift up all elements of stack b by 1.
 * The first element becomes the last one. 
 */
void	rb(int n, t_two *s)
{
	while (n > 0)
	{
		ft_stack_add_bottom(s->b, ft_stack_pop(s->b));
		print_op("rb");
		n--;
	}
}

/**
 * reverse rotate a - shift down all elements of stack a by 1.
 * The last element becomes the first one.
 */
void	rrb(int n, t_two *s)
{
	while (n > 0)
	{
		ft_stack_push(s->b, ft_stack_pop_bottom(s->b));
		print_op("rrb");
		n--;
	}
}
