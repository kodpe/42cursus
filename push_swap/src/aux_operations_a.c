/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_operations_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 06:06:44 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 07:13:05 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *  swap a - swap the first 2 elements at the top of stack a.
 */
void	sa(t_two *s)
{
	ft_stack_swap_top(s->a);
	print_op("sa");
}

/**
 * push a - take the first element at the top of b and put it at the top of a.
 */
void	pa(int n, t_two *s)
{
	while (n > 0)
	{
		ft_stack_push(s->a, ft_stack_pop(s->b));
		print_op("pa");
		n--;
	}
}

/**
 * rotate a - shift up all elements of stack a by 1.
 * The first element becomes the last one.
 */
void	ra(int n, t_two *s)
{
	while (n > 0)
	{
		ft_stack_add_bottom(s->a, ft_stack_pop(s->a));
		print_op("ra");
		n--;
	}
}

/**
 * reverse rotate a - shift down all elements of stack a by 1.
 * The last element becomes the first one.
 */
void	rra(int n, t_two *s)
{
	while (n > 0)
	{
		ft_stack_push(s->a, ft_stack_pop_bottom(s->a));
		print_op("rra");
		n--;
	}
}
