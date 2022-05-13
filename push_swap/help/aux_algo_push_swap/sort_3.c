/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 06:09:29 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/03 10:30:30by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	quick_sort_3(t_two *s)
{
	int	a;
	int	b;
	int	c;

	a = s->a->t[2];
	b = s->a->t[1];
	c = s->a->t[0];
	if (a < c && c < b)
		sa_ra(s);
	if (b < a && a < c)
		sa(s);
	if (b < c && c < a)
		ra(1, s);
	if (c < a && a < b)
		rra(1, s);
	if (c < b && b < a)
		ra_sa(s);
}

void	sort_3(t_two *s, int size)
{
	if (size == 3 && len(s->a) == 3)
	{
		quick_sort_3(s);
		// show(s);
		// db3(FI, LN, "sort_3 >> quicksort_3 OK");
	}
	else if (size == 2)
	{
		if (top(s->a) > top2(s->a))
			sa(s);
	}
	else if (size == 3)
	{
		while (size != 3 || !(top(s->a) < top2(s->a) && top2(s->a) < top3(s->a)))
		{
			if (size == 3 && top(s->a) > top2(s->a) && top3(s->a))
				sa(s);
			else if (size == 3
				&& !(top3(s->a) > top(s->a) && top3(s->a) > top2(s->a)))
			{
				pb(1, s);
				size--;
			}
			else if (top(s->a) > top2(s->a))
				sa(s);
			else if (size++)
				pa(1, s);
		}
		// show(s);
		// db3(FI, LN, "sort_3 A STRANGE AERA !!!!!!!!!!!!!!!!!!!!!!!");
	}
}

void	insortfrom_b(t_two *s, int len)
{
	int	i;
	int	imax;
	int	valmax;
	int	rb_count;

	// show(s);
	while (len)
	{
		imax = s->b->top;
		valmax = s->b->t[ft_stack_min(s->b)];
		i = 0;
		while (i < len)
		{
			if (s->b->t[s->b->top - i] > valmax)
			{
				imax = s->b->top - i;
				valmax = s->b->t[imax];
			}
			i++;
		}
		// ft_printf("max value %d\n", valmax);
		// dbv(FI, LN, "ft_stack nmax max", imax);
		rb_count = s->b->top - imax;
		rb(rb_count, s);
		pa(1, s);
		rrb(rb_count, s);
		len--;
		// show(s);
	}
}
