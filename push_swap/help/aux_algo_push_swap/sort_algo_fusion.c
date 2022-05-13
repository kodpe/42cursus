/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_fusion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:18:00 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 21:57:13 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
static void	show_v(t_two *s)
{
	int	i;

	i = 0;
	ft_printf("\n");
	while (i <= s->b->top)
	{
		ft_printf("%d ", s->b->t[i]);
		i++;
	}
	ft_printf(". ");
	i = s->a->top;
	while (i >= 0)
	{
		ft_printf("%d ", s->a->t[i]);
		i--;
	}
}
*/

/*
/////////////////////////////////////// FUSION MERGE V2 
static void	fu4_side_b(t_two *s, int len_part)
{
	int	compteur;
	int	na;
	int	nb;

	compteur = 0;
	na = len_part;
	nb = len_part;
	show_v(s);
	ft_printf("\nNA %d   NB %d   LEN PART %d\n", na, nb, len_part);
	while (na && nb)
	{
		if (top(s->a) < bot(s->b))
		{
			ft_printf("\nmerge %d\n", top(s->a));
			pb(1, s);
			na--;
			show_v(s);
		}
		else
		{
			ft_printf("\nmerge %d\n", bot(s->b));
			rrb(1, s);
			nb--;
			show_v(s);
		}
		compteur++;
	}
	ft_printf("\nNA %d   NB %d   LEN PART %d\n", na, nb, len_part);
	if (na)
	{
		ft_printf("\nmerge %d\n", bot(s->a));
		rra(na, s);
		na = 0;
		show_v(s);
		compteur++;

	}
	if (nb)
	{
		ft_printf("\nmerge %d\n", top(s->b));
		pa(nb, s);
		nb = 0;
		show_v(s);
		compteur++;
	}
	if (compteur == 2 * len_part)
		ft_printf("\nSUCCESS FU4\n");
	else
		ft_printf("\nFAILURE FU4 %d != %d\n", compteur, 2 * len_part);
	ft_printf("\nNA %d   NB %d   LEN PART %d\n", na, nb, len_part);
	show_v(s);
}

static void	fu4_side_a(t_two *s, int len_part)
{
	int	compteur;
	int	na;
	int	nb;

	compteur = 0;
	na = len_part;
	nb = len_part;
	show_v(s);
	ft_printf("\nNA %d   NB %d   LEN PART %d\n", na, nb, len_part);
	while (na && nb)
	{
		ft_printf("\nif %d > %d >> pa x stack a\n", top(s->b), bot(s->a));
		if (top(s->b) > bot(s->a))
		{
			ft_printf("\nmerge %d\n", top(s->b));
			pa(1, s);
			nb--;
			show_v(s);
		}
		else
		{
			ft_printf("\nmerge %d\n", bot(s->a));
			rra(1, s);
			na--;
			show_v(s);
		}
		compteur++;
	}
	ft_printf("\nNA %d   NB %d   LEN PART %d\n", na, nb, len_part);
	if (na)
	{
		ft_printf("\nmerge %d\n", bot(s->a));
		rra(na, s);
		na = 0;
		show_v(s);
		compteur++;

	}
	if (nb)
	{
		ft_printf("\nmerge %d\n", top(s->b));
		pa(nb, s);
		nb = 0;
		show_v(s);
		compteur++;
	}
	if (compteur == 2 * len_part)
		ft_printf("\nSUCCESS FU4\n");
	else
		ft_printf("\nFAILURE FU4 %d != %d\n", compteur, 2 * len_part);
	ft_printf("\nNA %d   NB %d   LEN PART %d\n", na, nb, len_part);
	show_v(s);
}
*/

////////////////////////////////////////////////////////////////////////////////
//                             OK LA ON EST BIEN                              //
////////////////////////////////////////////////////////////////////////////////
//
// 60/2 30 60%2 0	30/2 15 30%2 0	15/2 7 15%2 1	7/2 3  7%2 1	3/2 1 3%2 1
//
// 80u -> (20d 20d) -> (10q 10q) -> (5o 5o) -> (2oo 2oo 1oo) -> 1*32 1*32 +1oo
//

/*

			100 elements

	+50 PB
	+75
	125 PB

	

*/

void	divmod(int sizepart, int n, int *part, int *rest)
{
	*part = n / sizepart;
	*rest = n % sizepart;
}

static void	showresta(t_two *s, int rest, int *i)
{
	while (rest)
	{
		ft_printf("[%d] %d\n", *i, s->a->t[*i]);
		rest--;
		*i -= 1;
	}
}

static void	showrestb(t_two *s, int rest, int *i)
{
	while (rest)
	{
		ft_printf("[%d] %d\n", *i, s->b->t[*i]);
		rest--;
		*i -= 1;
	}
}

static void	showparta(t_two *s, int sizepart, int restinfront)
{
	int	part;
	int	rest;
	int	i;
	int	k;

	divmod(sizepart, ft_stack_len(s->a), &part, &rest);
	i = s->a->top;
	if (ft_stack_isempty(s->a))
	{
		ft_printf("SHOWPART A EMPTY i= %d\n", i);
		ft_putxnl(42, "=");
		return ;
	}
	ft_putnl();
	ft_putx(42, "=");
	ft_printf("\n A showpart %d ", sizepart);
	ft_printf("total %d  part %d  rest %d\n\n", ft_stack_len(s->a), part, rest);
	if (restinfront && rest)
		showresta(s, rest, &i);
	while (part)
	{
		ft_printf("%d.[%d - %d]", part, i , i - sizepart + 1);
		k = 0;
		while (k < sizepart)
		{
			ft_printf(" %d", s->a->t[i]);
			k++;
			i--;
		}
		ft_putnl();
		part--;
	}
	if (!restinfront && rest)
		showresta(s, rest, &i);
	if (i != -1)
		ft_printf("SHOWPART A ERROR i= %d\n", i);
	ft_putxnl(42, "=");
}

static void	showpartb(t_two *s, int sizepart, int restinfront)
{
	int	part;
	int	rest;
	int	i;
	int	k;

	divmod(sizepart, ft_stack_len(s->b), &part, &rest);
	i = s->b->top;
	if (ft_stack_isempty(s->b))
	{
		ft_printf("SHOWPART B EMPTY i= %d\n", i);
		ft_putxnl(42, "=");
		return ;
	}
	ft_putnl();
	ft_putx(42, "=");
	ft_printf("\n B showpart %d ", sizepart);
	ft_printf("total %d  part %d  rest %d\n\n", ft_stack_len(s->b), part, rest);
	if (restinfront && rest)
		showrestb(s, rest, &i);
	while (part)
	{
		ft_printf("%d.[%d - %d]", part, i , i - sizepart + 1);
		k = 0;
		while (k < sizepart)
		{
			ft_printf(" %d", s->b->t[i]);
			k++;
			i--;
		}
		ft_putnl();
		part--;
	}
	if (!restinfront && rest)
		showrestb(s, rest, &i);
	if (i != -1)
		ft_printf("SHOWPART B ERROR i= %d\n", i);
	ft_putxnl(42, "=");
}

void	showpart(t_two *s, int sizepart, int restinfront)
{
	showparta(s, sizepart, 0);
	showpartb(s, sizepart, 0);
	(void)restinfront;
}


void	m2swap(t_two *s)
{
	if (top(s->a) > top2(s->a) && top(s->b) < top2(s->b))
		ss(s);
	else if (top(s->a) > top2(s->a))
		sa(s);
	else if (top(s->b) < top2(s->b))
		sb(s);
	rr(2, s);
}

void	merge2(t_two *s)
{
	int	len_a;
	int	len_b;
	int	a;
	int	b;

	len_a = ft_stack_len(s->a);
	len_b = ft_stack_len(s->b);
	a = 0;
	b = 0;
	// +1 because we merge groupe by 2
	while (a + 1 < len_a && b + 1 < len_b)
	{
		m2swap(s);
		a += 2;
		b += 2;
	}
	/*
	if ( a != len_a && b != len_b)
	{
		pa
	}*/
		ft_printf("\nCOUNT A %d/%d COUNT B %d/%d\n", a, len_a, b, len_b);
	ft_printf("\nCOUNT A %d/%d COUNT B %d/%d\n", a, len_a, b, len_b);
}
/*
void	m2(t_two *s)
{
	int	total;
	int	part;
	int	rest;

	total = ft_stack_len(s->a);
	divmod(2, total, &part, &rest);
	while (part)
	{
		if (top(s->a) > top2(s->a) && top(s->b) < top2(s->b))
			ss(s);
		else if (top(s->a) > top2(s->a))
			sa(s);
		else if (top(s->b) < top2(s->b))
			sb(s);
		rr(2, s);
		part--;
	}
	if (rest)
		ft_printf("\nRESTE DE %d DANS A\n", rest);

	int	len_a;
	int	len_b;
	len_a = ft_stack_len(s->a);
	len_b = ft_stack_len(s->b);

	while (len_a >= 2 && len_b >= 2)
	{
		if (top(s->a) > top2(s->a) && top(s->b) < top2(s->b))
			ss(s);
		else if (top(s->a) > top2(s->a))
			sa(s);
		else if (top(s->b) < top2(s->b))
			sb(s);
		rr(2, s);
		len_a -= 2;
		len_b -= 2;
	}
	if (len_a == 2 && top(s->a) > top2(s->a))
	{
		sa(s);
		len_a -= 2;
	}
	if (len_b == 2 && top(s->b) < top2(s->b))
	{
		sb(s);
		len_b -= 2;
	}
	if (len_b == 1)
		rb(1, s);
}*/

static void	merge_aob(t_two *s, int sublen_a, int sublen_b)
{
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
	if (sublen_a)
		pb(sublen_a, s);
	if (sublen_b)
		rrb(sublen_b, s);
}

static void	merge_boa(t_two *s, int sublen_a, int sublen_b)
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

void	m4(t_two *s)
{
	int	tt;
	int	part;
	int	rest;

	tt = ft_stack_len(s->a);
	divmod(2, tt, &part, &rest);
	ft_printf("A tt %d  part %d  rest %d\n\n", tt, part, rest);
	//tt = ft_stack_len(s->b);
	//divmod(2, tt, &part, &rest);
	//ft_printf("B tt %d  part %d  rest %d\n\n", tt, part, rest);

	int	i;

	i = 0;
	while (i <= part / 2)
	{
		merge_boa(s, 2, 2);
		i++;
	}
	ft_printf("tt %d  part %d  i %d\n\n", tt, part, i);
	//rra(, s);
	/*
	while (i < part)
	{
		merge_aob(s, 2, 2);
		i++;
	}
	*/
}

void	merge4(t_two *s)
{
	int	len_a;
	int	len_b;
	int	a;
	int	b;

	len_a = ft_stack_len(s->a);
	len_b = ft_stack_len(s->b);
	a = 0;
	b = 0;
	while (a + 2 < len_a && b + 2 < len_b)
	{
		//////////////////////////
		if (top(s->b) > bot(s->a))
		{
			pa(1, s);
			b++;
		}
		else
		{
			rra(1, s);
			a++;
		}
		//////////////////////////
		if (top(s->b) > bot(s->a))
		{
			pa(1, s);
			b++;
		}
		else
		{
			rra(1, s);
			a++;
		}
	}
	ft_printf("\nCOUNT A %d/%d COUNT B %d/%d\n", a, len_a, b, len_b);
}
/*
static void	merge_to_top_a(t_two *s, int actualsizegroup)
{
	// merge top b && bot a => top a sizegroup or - 
		sizegroup result is sizegroup * 2 or -
	//
	int	len_a;
	int	len_b;
	int	a;
	int	b;

	len_a = ft_stack_len(s->a);
	len_b = ft_stack_len(s->b);
	while (len_a && len_b)
	{
		a = 0;
		b = 0;
		while (a < actualsizegroup && b < actualsizegroup)
		{
			if (len_a && len_b)
			{
				if (top(s->b) > bot(s->a))
				{
					pa(1, s);
					b++;
					len_b--;
				}
				else
				{
					rra(1, s);
					a++;
					len_a--;
				}
			}
			else if (len_a)
			{
				rra(1, s);
				a++;
				len_a--;
			}
			else if (len_b)
			{
				pa(1, s);
				b++;
				len_b--;
			}
		}
	}
}*/

void	extra_big_vip_fusion_strike_improved_v42(t_two *s)
{
	/* je veux faire des groupes de 2, j'ai tout dans a, b est vide
				=> donc besoin d'un equilibrage
				cb de groupes de 2 tout / 2
				=> 19/2 = 9 gruopes de 2 est ce qu il y a un reste ? %
				mettre la moitie dans b autre moitie dans a
				*/


	int	global_size;
	int	i;

	global_size = ft_stack_len(s->a);
	pb(global_size / 2, s);
	show(s);
	merge2(s);
	//merge4(s);
	//showpart(s, 2, 0);
	show(s);
	return ;
	m4(s);
	//showpart(s, 4, 0);
	show(s);
	return ;
	///////////////////////////////////// 
	i = 0;
	while (i < global_size / 8)
	{
		merge_boa(s, 2, 2);
		i++;
	}
	rra(ft_stack_len(s->a) - (global_size / 8) * 4, s);
	i = 0;
	int	len_b;
	len_b = ft_stack_len(s->b);
	while (i < len_b / 8)
	{
		merge_aob(s, 2, 2);
		i++;
	}
	showpart(s, 4, 1);
	return ;
}
