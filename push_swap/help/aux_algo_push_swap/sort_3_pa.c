/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_pa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:30:04 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/04 12:30:53 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	bca(t_two *s)
{
	sb(s);
	pa(1, s);
	sb(s);
	pa(2, s);
}

static void	cab(t_two *s)
{
	rb(1, s);
	sb(s);
	pa(1, s);
	rrb(1, s);
	pa(2, s);
}

static void	cba(t_two *s)
{
	rb(1, s);
	sb(s);
	pa(2, s);
	rrb(1, s);
	pa(1, s);
}

static void	push_a_abc(t_two *s, int a, int b, int c)
{
	if (a > b && b > c)
		pa(3, s);
	if (a > c && c > b)
	{
		pa(1, s);
		sb(s);
		pa(2, s);
	}
	if (c > a && a > b)
		cab(s);
	if (b > a && a > c)
	{
		sb(s);
		pa(3, s);
	}
	if (b > c && c > a)
		bca(s);
	if (c > b && b > a)
		cba(s);
}

void	sort_3_pa(t_two *s, int len)
{
	if (len == 1)
		pa(1, s);
	if (len == 2)
	{
		if (top(s->b) < top2(s->b))
			sb(s);
		pa(2, s);
	}
	if (len == 3)
		push_a_abc(s, top(s->b), top2(s->b), top3(s->b));
}
