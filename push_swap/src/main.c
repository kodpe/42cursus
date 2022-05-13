/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:27:13 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 13:17:29 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*** CLEAN LIBFT DEBUG !!!!!!!!!!!!! **/

#include "push_swap.h"

static int	free_all(t_two *s)
{
	if (s)
	{
		if (s->a)
			ft_stack_del(s->a);
		if (s->b)
			ft_stack_del(s->b);
		free(s);
	}
	return (0);
}

static void	insort(t_two *s, int len)
{
	pb(len, s);
	while (len)
	{
		uptop_b(s, ft_stack_max(s->b, len));
		pa(1, s);
		len--;
	}
}

static void	pushswap_sort(t_two *s, int len)
{
	if (len <= 5)
		smallsort(s, len);
	else if (len <= 20)
		insort(s, len);
	else
		smart_insort(s, len);
}

int	main(int ac, char **av)
{
	t_two	*s;

	if (ac < 2)
		return (1);
	s = (t_two *)malloc(sizeof(t_two));
	if (!s)
		error_exit("main malloc failed");
	s->a = parse(ac, av);
	s->b = ft_stack_new(ac - 1);
	if (!s->a || !s->b)
	{
		free_all(s);
		return (1);
	}
	if (s->a->capacity == 1 || ft_stack_ascs(s->a))
	{
		if (PUSHSWAP_MSG)
			ft_printf("one element or already soorted\n");
		return (free_all(s));
	}
	pushswap_sort(s, len(s->a));
	summary_check(s, ac -1);
	return (free_all(s));
}
