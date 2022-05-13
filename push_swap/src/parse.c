/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 06:30:38 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 05:01:27 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_av(int ac, char **av)
{
	int	i;
	int	k;

	i = 1;
	while (i < ac)
	{
		k = 0;
		if (ft_issign(av[i][0]))
		{
			k = 1;
			if (!av[i][k])
				return (0);
		}
		while (av[i][k])
		{
			if (!ft_isdigit(av[i][k]))
				return (0);
			k++;
		}
		i++;
		if (k > 18)
			return (0);
	}
	return (1);
}

static int	valid_int(t_stack *a, char **av, int capacity)
{
	int		i;
	long	n;

	a->top = capacity - 1;
	i = 0;
	while (i < capacity)
	{
		n = ft_atol_severe(av[capacity - i]);
		if (n < -2147483648 || n > 2147483647)
		{
			return (0);
		}
		a->t[i] = (int)n;
		i++;
	}
	return (1);
}

t_stack	*parse(int ac, char **av)
{
	t_stack	*a;
	int		capacity;

	if (!valid_av(ac, av))
		return (error_null("parse invalid arg"));
	capacity = ac - 1;
	a = ft_stack_new(capacity);
	if (!a)
		return (error_null("parse stack a malloc failed"));
	if (!valid_int(a, av, capacity))
		return (error_null_free_stack(a, "parse no integer"));
	if (!ft_tab_are_distinct(a->t, a->capacity))
		return (error_null_free_stack(a, "parse no distinct"));
	return (a);
}
