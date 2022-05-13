/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_range_sorter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:25:34 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 21:57:25 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	up_a(t_two *s, int index)
{
	if (index >= s->a->top / 2)
		ra(s->a->top - index, s);
	else
		rra(index + 1, s);
}

static int	up_a_others_b(t_two *s, int index)
{
	if (index >= s->a->top / 2)
	{
		//ft_printf("\nUP %d(=%d) by PB WAY\n", index, s->a->t[index]);
		int	nra = s->a->top - index;
		//ft_printf("\ndo x %d RA\n", nra); 
		ra(nra, s);
		pb(1, s);
		int	cpt = 1;
		while (top(s->a) == top(s->b) + 1)
		{
			pb(1, s);
			cpt++;
		}
		rra(nra, s);
		return (cpt);
	}
	else
	{
		//ft_printf("\nUP %d(=%d) by RRA WAY\n", index, s->a->t[index]);
		int	i;

		i = 0;
		while (i < index)
		{
			rra(1, s);
			pb(1, s);
			i++;
		}
		rra(1, s);
		sa(s);				// swap 1-0 => 0-1
		return (index);
	}
}

static int	right_place(t_two *s, int i)
{
	int	n;

	n = s->a->top;
	while (s->a->t[n] < s->a->t[i])
	{
		//ft_printf("t[%d] %d < %d t[i=%d]\n", n, s->a->t[n], s->a->t[i], i);
		n--;
	}
	return (n);
}

static void	sorter(t_two *s, int index_to_sort)
{
	int	i;
	int	r;

	r = right_place(s, index_to_sort);
	//ft_printf("right place for i = %d (%d) is i = %d\n", index_to_sort, s->a->t[index_to_sort], r);
	//ft_printf("\nSTARTING\n");
	if (r == index_to_sort)
	{
		//ft_printf("\n-- no way already right place\n");
		return ;

	}
	int previous_a_sorted = s->a->top - (r + 1);
	//ft_printf("previous_a_sorted is %d\n", previous_a_sorted);
	pb(previous_a_sorted, s);
	int	val_max_pre;
	
	val_max_pre = ft_stack_min(s->a);
	if (!ft_stack_isempty(s->b))
		val_max_pre = top(s->b);
	//ft_printf("val_max_pre is %d\n", val_max_pre);

	int	tmpbot_a_unsorted = up_a_others_b(s, index_to_sort);
	//ft_printf("tmp_bot_a_unsorted is %d\n", tmpbot_a_unsorted);
	i = 0;
	// check for bot a before b => top a => pa
	while (i < tmpbot_a_unsorted)
	{
		/**
		 * 							BOT JUMP CARE IA
		 * if bot a > top a
		 * 
		 * .... if bot2 a < top a
		 * 			do rra + pb
		 * 			while bot a < top a && bot a > top2 b
		 * 				do rra
		 * 				if bot a > top a && bot a < top2 a
		 * 					do rra + sa
		 * 			do pa + ra
		 *
		 * .... else if bot2 a < top2 a
		 * 			do rra + pb
		 *  		do rra + sa
		 * 			do pa + ra
		 * 
		 */
		if (bot(s->a) > top(s->a))
		{
			if (bot2(s->a) < top(s->a))
			{
				rra(1, s);
				pb(1, s);
				while (bot(s->a) < top(s->a) && bot(s->a) > val_max_pre)
				{
					rra(1, s);
					if (bot(s->a) > top(s->a) && bot(s->a) < top2(s->a))
					{
						rra(1, s);
						sa(s);
					}
				}
				pa(1, s);
				ra(1, s);
			}
			else if (bot2(s->a) < top2(s->a))
			{
				rra(1, s);
				pb(1, s);
				rra(1, s);
				sa(s);
				pa(1, s);
				ra(1, s);
			}
		}
		pa(1, s);
		if (top(s->a) > top2(s->a) && top(s->a) < s->a->t[s->a->top - 2])
			sa(s);
		else
			ra(1, s);
		i++;
	}
	// apres on remet ce qu'on a mit dans b dans a avec optimisation de bot(s->a)
	// on cherche si on peut mettre entre temps des valeurs du bot a dans le top a
	i = previous_a_sorted;
	while (i > 0)
	{
		/**
		 * while i && top b == top a - 1
		 *		do pa  i++
		 */
		while (i && top(s->b) == top(s->a) - 1)
		{
			pa(1, s);
			i--;
		}
		/**
		 * while bot a < top a && bot a > top b
		 *		do rra
		 * 		while bot a > top a && bot a < top2 a	
		 * 			do rra + sa
		 * 		while i && (val) top b - 1 == bot a && bot a < top a
		 * 			do pa + rra   i++
		 */
		while (bot(s->a) < top(s->a) && bot(s->a) > val_max_pre)
		{
			rra(1, s);
			while (bot(s->a) > top(s->a) && bot(s->a) < top2(s->a))
			{
				rra(1, s);
				sa(s);
			}
			while (i && top(s->b) - 1 == bot(s->a) && bot(s->a) < top(s->a))
			{
				pa(1, s);
				rra(1, s);
				i--;
			}
		}
		/**
		 * 							BOT JUMP CARE IA
		 * if bot a > top a
		 * 
		 * .... if bot2 a < top a
		 * 			do rra + pb
		 * 			while bot a < top a && bot a > top2 b
		 * 				do rra
		 * 				if bot a > top a && bot a < top2 a
		 * 					do rra + sa
		 * 			do pa + ra
		 *
		 * .... else if bot2 a < top2 a
		 * 			do rra + pb
		 *  		do rra + sa
		 * 			do pa + ra
		 * 
		 */
		if (bot(s->a) > top(s->a))
		{
			if (bot2(s->a) < top(s->a))
			{
				rra(1, s);
				pb(1, s);
				while (bot(s->a) < top(s->a) && bot(s->a) > top2(s->b))
				{
					rra(1, s);
					if (bot(s->a) > top(s->a) && bot(s->a) < top2(s->a))
					{
						rra(1, s);
						sa(s);
					}
				}
				pa(1, s);
				ra(1, s);
			}
			else if (bot2(s->a) < top2(s->a))
			{
				rra(1, s);
				pb(1, s);
				rra(1, s);
				sa(s);
				pa(1, s);
				ra(1, s);
			}
		}
		if (i)
		{
			pa(1, s);
			i--;
		}
	}
	return;
	////////////////////////// END OF RANGE SORTER
	up_a(s, 20);
}

/**
 *       13 12 11  10 9  8
 *  test -1  0  2  1  4  6 8 12 14 17 18 19 20 21
 * 1 2 3 4 5 89 83478 747 7
 */

/*
--- n fois
rra ++
pb ++
----
rra
--- n fois
pa
ra
---


*/
void	range_sorter(t_two *s)
{
	int min;
	int len;
	int k;

	min = ft_stack_min(s->a);
	if (min >= s->a->top / 2)
		ra(s->a->top - min, s);
	else
		rra(min + 1, s);
	len = s->a->top;
	k = len;
	//ft_printf("\e[1;31m S1 K %d  LEN %d  MIN %d\n", k, len, min);
	/**/
	k = s->a->top;
	while (k >= 0)
	{
		sorter(s, k);
		k--;
	} /**/
}
