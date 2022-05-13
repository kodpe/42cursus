/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_operations_smart.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 06:07:18 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 13:22:08 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**	
 * Do rotate or reverse rotate to change the first element in the stack.
 */
void	uptop_a(t_two *s, int pos)
{
	if (pos >= s->a->top / 2)
		ra(s->a->top - pos, s);
	if (pos < s->a->top / 2)
		rra(pos + 1, s);
}

void	uptop_b(t_two *s, int pos)
{
	if (pos >= s->b->top / 2)
		rb(s->b->top - pos, s);
	if (pos < s->b->top / 2)
		rrb(pos + 1, s);
}

/**	
 * Save the number of operations needed (rotate or reverse rotate)
 * to change the first element in the stack.
 */
void	count_uptop_a(t_two *s, int pos)
{
	s->n_ra = 0;
	s->n_rra = 0;
	if (pos >= s->a->top / 2)
		s->n_ra = s->a->top - pos;
	if (pos < s->a->top / 2)
		s->n_rra = pos + 1;
}

void	count_uptop_b(t_two *s, int pos)
{
	s->n_rb = 0;
	s->n_rrb = 0;
	if (pos >= s->b->top / 2)
		s->n_rb = s->b->top - pos;
	if (pos < s->b->top / 2)
		s->n_rrb = pos + 1;
}

/**
 * Do double operations (rr or rrr) then simple operations (rb ra rrb rra)
 */
void	do_rotations(t_two *s)
{
	while (s->n_ra && s->n_rb)
	{
		rr(1, s);
		s->n_ra--;
		s->n_rb--;
	}
	while (s->n_rra && s->n_rrb)
	{
		rrr(1, s);
		s->n_rra--;
		s->n_rrb--;
	}
	rb(s->n_rb, s);
	ra(s->n_ra, s);
	rrb(s->n_rrb, s);
	rra(s->n_rra, s);
}
