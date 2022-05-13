/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_shortcuts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 06:07:30 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 06:07:31 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_min(t_stack *s, int min)
{
	if (s->top + 1 < min)
		error_exit("CRITICAL check_min() size < min");
}

/**
 * return the first value of stack
 */
int	top(t_stack *s)
{
	check_min(s, 1);
	return (s->t[s->top]);
}

/**
 * return the second value of stack
 */
int	top2(t_stack *s)
{
	check_min(s, 2);
	return (s->t[s->top - 1]);
}

/**
 * return the third value of stack
 */
int	top3(t_stack *s)
{
	check_min(s, 3);
	return (s->t[s->top - 2]);
}

/**
 * return the length of stack
 */
int	len(t_stack *s)
{
	if (!s)
		error_exit("CRITICAL len() !s");
	return (s->top + 1);
}
