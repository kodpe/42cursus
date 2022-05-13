/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_insort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 04:12:24 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 13:16:18 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	part(t_two *s)
{
	int	quart;
	int	pivot;
	int	i;

	pivot = 0;
	if (!ft_stack_median(&pivot, s->a, len(s->a)))
		pivot = s->a->top / 2;
	quart = ft_tab_firstquart(s->a->t, len(s->a));
	i = s->a->top;
	while (i)
	{
		if (top(s->a) < pivot)
		{
			pb(1, s);
			if (top(s->b) < quart)
				rb(1, s);
		}
		else
			ra(1, s);
		i--;
	}
}

static int	find_place_in_a(t_two *s, int val)
{
	int	pos;
	int	alen;

	val = s->b->t[val];
	if (ft_stack_isempty(s->a))
		return (-1);
	pos = ft_stack_min(s->a, len(s->a));
	alen = len(s->a);
	while (alen)
	{
		if (val < s->a->t[pos])
			return (pos);
		pos--;
		if (pos == -1)
			pos = s->a->top;
		alen--;
	}
	pos = ft_stack_min(s->a, len (s->a));
	return (pos);
}

static int	find_best_index_in_b(t_two *s)
{
	int	best_index;
	int	*score;
	int	blen;
	int	i;

	blen = len(s->b);
	score = ft_newtab(blen);
	if (!score)
		return (s->b->top);
	i = 0;
	while (i < blen)
	{
		count_uptop_b(s, i);
		count_uptop_a(s, find_place_in_a(s, i));
		score[i] = s->n_ra + s->n_rb + s->n_rra + s->n_rrb;
		i++;
	}
	best_index = ft_tab_min(score, blen);
	free(score);
	return (best_index);
}

void	smart_insort(t_two *s, int size)
{
	int	i;

	part(s);
	pb(len(s->a) - 5, s);
	smallsort(s, 5);
	size = len(s->b);
	while (size)
	{
		i = find_best_index_in_b(s);
		count_uptop_b(s, i);
		count_uptop_a(s, find_place_in_a(s, i));
		do_rotations(s);
		pa(1, s);
		size--;
	}
	uptop_a(s, ft_stack_min(s->a, len(s->a)));
	return ;
}
