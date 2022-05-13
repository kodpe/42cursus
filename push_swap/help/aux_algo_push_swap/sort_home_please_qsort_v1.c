/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:53:23 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/31 11:41:25 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	please_qsort(t_two *s)
{
	int	med;
	int	bot;

	ft_printf("STATE 1 A: improved qsort [15;++]\n");//FIXME
	ft_printf("EXIT 7\n");//FIXME
	return ;
	med = ft_tab_median(s->a->t, s->a->top + 1);
	bot = 0;
	for	(int top = s->a->top; top >= bot; top--)
	{
		ft_printf("MEDIAN %d\n", med);
		if (s->a->t[top] > med)
			pb(1, s);
		else
		{
			top++;
			bot++;
			ra(1, s);
		}
		show(s);
	}
	// si j ai <= 15 elelemts alors insort a et ou b
}

static void	please_insort(t_two *s)
{
	int	size;

	ft_printf("STATE 1 A: improved insort [6;14]\n");//FIXME
	ft_printf("EXIT 7\n");//FIXME
	return ;
	size = len(s->a);
	while (size > 0)
	{
		if (len(s->a) >= 3)
			if (top2(s->a) < top(s->a))
				sa(s);
		if (bot(s->a) < top(s->a))
			rra(1, s);
		pb(1, s);
		if (len(s->b) >= 2)
		{
			if (top2(s->b) > top(s->b))
				sb(s);
		}
		size--;
	}
	/*
	if (ft_stack_issort_des(s->b))
		ft_printf("OK B DESCENDING SUCCESSSS\n");
		*/
	size = len(s->b);
	while (size > 0)
	{
		pa(1, s);
		if (len(s->a) >= 2)
			if (top2(s->a) < top(s->a))
				sa(s);
		size--;
	}
	//ft_printf("  \e[1;33moperations count > %d <\n\e[0m", s->count);
}

void	sort(t_two *s, int size)
{
	if (size <= 5)
		tinysort(s, size);
	if (size >= 6)
		quick_sort_a(s, ft_stack_len(s->a));
	show(s);
	db(FI, LN, "end of sort");
	return ;
	///  FIXME   ///
	please_qsort(s);
	please_insort(s);
}
