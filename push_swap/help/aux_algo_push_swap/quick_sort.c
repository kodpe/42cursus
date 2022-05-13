/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 06:06:22 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/04 12:33:36 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	quicksort_a(t_two *s, int len)
{
	int		pivot;
	int		below;
	int		n;

	if (ft_stack_asc(s->a, len))
		return (1);
	if (len <= 3)
	{
		sort_3(s, len);
		return (1);
	}
	if (!ft_stack_median(&pivot, s->a, len))
		return (0);
	below = 0;
	n = len;
	while (len != n / 2 + n % 2)
	{
		if (top(s->a) < pivot && (len--))
			pb(1, s);
		else if ((++below))
			ra(1, s);
	}
	while (n / 2 + n % 2 != ft_stack_len(s->a) && below)
	{
		rra(1, s);
		below--;
	}
	return (quicksort_a(s, n / 2 + n % 2) && quicksort_b(s, n / 2));
}

int	quicksort_b(t_two *s, int len)
{
	int		pivot;
	int		below;
	int		n;

	if (ft_stack_des(s->b, len))
	{
		while (len--)
			pa(1, s);
	}
	if (len <= 3)
	{
		sort_3_pa(s, len);
		return (1);
	}
	if (!ft_stack_median(&pivot, s->b, len))
		return (0);
	below = 0;
	n = len;
	while (len != n / 2)
	{
		if (top(s->b) >= pivot && len--)
			pa(1, s);
		else if (++below)
			rb(1, s);
	}
	while (n / 2 != ft_stack_len(s->b) && below)
	{
		rrb(1, s);
		below--;
	}
	return (quicksort_a(s, n / 2 + n % 2) && quicksort_b(s, n / 2));
}
