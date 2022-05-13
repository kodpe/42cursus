/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:38:13 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 07:36:41 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_abc(t_two *s)
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

static void	pb_min(t_two *s)
{
	int	min;

	min = ft_stack_min(s->a, len(s->a));
	if (min == s->a->top - 1)
		sa(s);
	else if (min == 2)
		ra(2, s);
	else if (min == 1)
		rra(2, s);
	else if (min == 0)
		rra(1, s);
	pb(1, s);
}

void	smallsort(t_two *s, int len)
{
	if (len == 5)
		pb_min(s);
	if (len == 5 || len == 4)
		pb_min(s);
	if (len >= 3)
		sort_abc(s);
	if (len == 5)
		pa(2, s);
	if (len == 4)
		pa(1, s);
	if (len == 2)
		sa(s);
}
