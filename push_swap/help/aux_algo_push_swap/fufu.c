/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fufu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 01:49:20 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/31 07:12:55 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	divideby2(t_two *s)
{
	int	grp4;
	int	rest;
	int	i;

	grp4 = ft_stack_len(s->a) / 4;
	rest = ft_stack_len(s->a) % 4;
	i = 0;
	while (i < grp4)
	{
		pb(2, s);
		if (top(s->a) > top2(s->a) && top(s->b) < top2(s->b))
			ss(s);
		else if (top(s->b) < top2(s->b))
			sb(s);
		else if (top(s->a) > top2(s->a))
			sa(s);
		ra(2, s);
		i++;
	}
	if (rest)
		ft_printf("\nREST %d el in A\n", rest); // FIXME
	if (rest == 3)
	{
		pb(1, s);
		rb(1, s);
		if (top(s->a) > top2(s->a))
			sa(s);
		rest -= 3;
	}
	if (rest == 2)
	{
		if (top(s->a) > top2(s->a))
			sa(s);
		rest -= 2;
	}
	if (rest)
	{
		pb(1, s);
		rb(1, s);
		rest--;
	}
	if (rest)
		ft_printf("\nREST %d el in A\n", rest); // FIXME
}

static void	merge_to_b(t_two *s, int sublen_a, int sublen_b)
{
	showm(s, 4);
	db(FI, LN, "merge to b startwhile");
	while (sublen_a && sublen_b)
	{
		if (top(s->a) < bot(s->b))
		{
			pb(1, s);
			sublen_a--;
		}
		else
		{
			rrb(1, s);
			sublen_b--;
		}
	}
	/*
	if (sublen_b)
	{
		dbv(FI, LN, "sublen b", sublen_b);
		pa(sublen_b, s);
		showm(s, 4);
	}
	if (sublen_a)
		pb(sublen_a, s);
	*/
	dbv(FI, LN, "sublen b", sublen_b);
	dbv(FI, LN, "sublen a", sublen_a);
}

static void	merge_to_a(t_two *s, int sublen_a, int sublen_b)
{
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

static void	doublemerge(t_two *s, int n, int sizegroup)
{
	int	i;

	i = 0;
	while (i < n)
	{
		merge_to_a(s, sizegroup, sizegroup);
		i++;
	}
	rra(n * sizegroup, s);
	// dbv(FI, LN, "n", n);
	// dbv(FI, LN, "sizegroup", sizegroup);
	showm(s, 4);
	int	rest = ft_stack_len(s->b) % sizegroup;
	dbv(FI, LN, "rest", rest);
	i = 0;
	if (rest)
	{
		merge_to_b(s, sizegroup, rest);
		i++;
	}
	while (i < n)
	{
		merge_to_b(s, sizegroup, sizegroup);
		i++;
	}
	return ;
}

static void	mergeme(t_two *s, int newsizegroup)
{
	int	oldsizegroup;

	oldsizegroup = newsizegroup / 2;
	ft_printf("mergeme newsizegroup is %d\n", newsizegroup);
	ft_printf("mergeme oldsizegroup is %d\n", oldsizegroup);

	int	len_a;
	int	len_b;

	len_a = ft_stack_len(s->a);
	len_b = ft_stack_len(s->b);

	int	nbr_gr2_a;
	int	nbr_gr2_b;
	int	nbr_gr4;

	nbr_gr2_a = len_a / oldsizegroup + len_a % oldsizegroup;
	nbr_gr2_b = len_b / oldsizegroup + len_b % oldsizegroup;
	nbr_gr4 = (nbr_gr2_a + nbr_gr2_b) / 2;

	ft_printf("mergeme nbr_gr2_a is %d\n", nbr_gr2_a);
	ft_printf("mergeme nbr_gr2_b is %d\n", nbr_gr2_b);
	ft_printf("mergeme nbr_gr4 is %d\n", nbr_gr4);

	doublemerge(s, nbr_gr4 / 2, 2);

		//new_merge_a(s, 4);
		//new_merge_b(s, 4);

}

void	fufu(t_two *s)
{
	showm(s, 1);
	db(FI, LN, "fufu start");
	divideby2(s); // 4 cas possibles
	showm(s, 2);
	db(FI, LN, "fufu merge by 4");
	mergeme(s, 4);
	showm(s, 4);
	//mergeme(s, 8);
	return ;
}
