/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_merge_v1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:22:17 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 21:57:17 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


/**
 * merge dest top a
 * b && a is already full sorted
 * merge top b with bot a
 */
static void	merge_top_b_and_bot_a(t_two *s, int sublen_a, int sublen_b)
{
	// quand B a une batch sorted DESC && A a une batch ASC
	// nb taille batch b [ 0 -----| batch b ----> nb >> pa]
	// na taille batch a [ new batch | ------ | na <------- rra]
	while (sublen_a && sublen_b)
	{
		if (top(s->b) > bot(s->a))
		{
			pa(1, s);
			sublen_b--;
		}
		else
		{
			rra(1, s);
			sublen_a--;
		}
	}
	if (sublen_a)
		rra(sublen_a, s);
	if (sublen_b)
		pa(sublen_b, s);
}

/**
 *	SIMPLE SORT B DESC 
 */
static void	b_abc(t_two *s)
{
	int	a;
	int	b;
	int	c;

	a = s->b->t[2];
	b = s->b->t[1];
	c = s->b->t[0];
	if (a > c && c > b)
	{
		sb(s);
		rb(1, s);
	}
	if (b > a && a > c)
		sb(s);
	if (b > c && c > a)
		rb(1, s);
	if (c > a && a > b)
		rrb(1, s);
	if (c > b && b > a)
	{
		rb(1, s);
		sb(s);
	}
}

static void	max_ontop_b(t_two *s)
{
	int	max;

	max = ft_stack_max(s->b);
	if (max >= s->b->top / 2)
		rb(s->b->top - max, s);
	else
		rrb(max + 1, s);
}

static void	msort_b(t_two *s)
{
	int	len;
	int	len_ori;

	len = ft_stack_len(s->b);
	len_ori = len;
	while (len > 3)
	{
		max_ontop_b(s);
		pa(1, s);
		len--;
	}
	b_abc(s);
	pb(len_ori - 3, s);
}

/**
 *	SIMPLE SORT A ASC
 */
static void	a_abc(t_two *s)
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

static void	min_ontop_a(t_two *s)
{
	int	min;

	min = ft_stack_min(s->a);
	if (min >= s->a->top / 2)
		ra(s->a->top - min, s);
	else
		rra(min + 1, s);
}

static void	msort_a(t_two *s)
{
	int	len;
	int	len_ori;

	len = ft_stack_len(s->a);
	len_ori = len;
	while (len > 3)
	{
		min_ontop_a(s);
		pb(1, s);
		len--;
	}
	a_abc(s);
	pa(len_ori - 3, s);
}
/////////////////////////////////////////////// END SIMPLE SORT A

/**
 * split a in a and b 
 * then
 * pb smallest a in b a-3
 * then pa a-3
 * so pa is sorted
 * 
 * do same with b:
 * push biggest b in a b-3
 * then pb b-3
 */

//////////////////////////
void	merge_v0(t_two *s) // NO MERGE (juste smallest to b the all pa)
{
	msort_a(s);
}

//////////////////////////
void	merge_v1(t_two *s)
{
	int	len_b;
	int	len_a;
	
	len_b = ft_stack_len(s->a) / 2;
	len_a = ft_stack_len(s->a) - len_b;
	pb(len_b, s);
	// split a in a and b
	msort_a(s);
	msort_b(s);
	// MERGE to TOP A ( biggest to smallest)
	merge_top_b_and_bot_a(s, len_a, len_b);
}

//////////////////////////
static void	v2min_ontop_a(t_two *s)
{
	int	min;

	min = ft_stack_min(s->a);
	if (min >= s->a->top / 2)
		ra(s->a->top - min, s);
	else
		rra(min + 1, s);
}

static void	v2msort_a(t_two *s)
{
	int	len;
	int	len_ori;

	len = ft_stack_len(s->a);
	len_ori = len;
	while (len > 3)
	{
		v2min_ontop_a(s);
		pb(1, s);
		len--;
	}
	a_abc(s);
	pa(len_ori - 3, s);
}

void	merge_v2(t_two *s)
{
	int	len;
	int	med;
	int	q1;
	int	q3;
	int	i;

	len = ft_stack_len(s->a);
	med = ft_tab_median(s->a->t, len);
	q1 = ft_tab_first_quar(s->a->t, len);
	q3 = ft_tab_third_quar(s->a->t, len);
	(void)q3;
	i = 0;
	while (i < len)
	{
		if (top(s->a) <= q1)
			pb(1, s);
		else
			ra(1, s);
		i++;
	}
	msort_b(s);
	show(s);
	i = 0;
	while (i < len)
	{
		if (top(s->a) <= med)
			pb(1, s);
		else
			ra(1, s);
		i++;
	}
	show(s);
	msort_b(s);
	show(s);
	msort_a(s);
	show(s);
	//
	// MERGE to TOP A ( biggest to smallest)
	int len_b = ft_stack_len(s->b);
	int len_a = ft_stack_len(s->a);
	merge_top_b_and_bot_a(s, len_a, len_b);
	return ;
	v2msort_a(s);
}
