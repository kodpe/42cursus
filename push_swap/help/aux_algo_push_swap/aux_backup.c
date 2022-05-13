/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:18:01 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/02 11:14:57 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <sys/ioctl.h> // FIXME

void	print_op(char *op)
{
	if (ERROR_INFO)
		ft_printf("\e[0;33m %s\e[0m", op);
	else
		ft_printf("%s\n", op);
}

int	len(t_stack *s)
{
	if (!s)
	{
		ft_printf("\e[0;31mERR len !s\n\e[0m");
		exit(1);
	}
	return (s->top + 1);
}

void	check_minlen(t_stack *s, int min)
{
	if (s->top + 1 < min)
	{
		ft_printf("\e[0;31mERR minlen %d < %d min\n\e[0m", s->top + 1, min);
		exit(1);
	}
}

int	top(t_stack *s)
{
	check_minlen(s, 1);
	return (s->t[s->top]);
}

int	top2(t_stack *s)
{
	check_minlen(s, 2);
	return (s->t[s->top - 1]);
}

int	top3(t_stack *s)
{
	check_minlen(s, 3);
	return (s->t[s->top - 2]);
}

/*
int	bot(t_stack *s)
{
	check_minlen(s, 1);
	return (s->t[0]);
}

int	mid(t_stack *s)
{
	if (ft_stack_isempty(s))
	{
		ft_printf("\e[0;31mERR top > isempty\n\e[0m");
		exit(1);
	}
	return (s->t[s->top / 2]);
}

int	bot2(t_stack *s)
{
	if (len(s) < 1)
	{
		ft_printf("\e[0;31mERR bot2 > isempty\n\e[0m");
		exit(1);
	}
	return (s->t[1]);
}

*/

/*

static void	showmerge(t_two *s, int size)
{
	int	top;
	int	i;

	top = s->b->top;
	ft_printf("\e[1;35m\n(B %d)  \e[0m", top + 1);
	i = 0;
	while (i <= top)
	{
		if (i > 0)
			if (s->b->t[i] > s->b->t[i - 1])
				ft_printf("\e[0;35m");
		ft_printf("%d", s->b->t[i]);
		ft_printf("\e[0m");
		if (i < top && top % size == 0 && i % size == 0)
			ft_printf(" | ");
		else if (i < top && top % size == 1 && i % size == 1)
			ft_printf(" | ");
		else
			ft_printf(" ");
		i++;
	}
	ft_printf("    ");
	i = s->a->top;
	while (i >= 0)
	{
		if (i > 0)
			if (s->a->t[i] < s->a->t[i - 1])
				ft_printf("\e[0;34m");
		ft_printf("%d", s->a->t[i]);
		if (i > 0 && i % size == 0)
			ft_printf(" | ");
		else
			ft_printf(" ");
		ft_printf("\e[0m");
		i--;
	}
	ft_printf("\e[1;34m  (A %d)\e[0m\n", s->a->top + 1);
}

void	showm(t_two *s, int size)
{
	if (ERROR_INFO)
	{
		showmerge(s, size);
		nl();
	}
}
*/

void	show(t_two *s)
{
	if (ERROR_INFO)
	{
		// showmerge(s);
		ft_stack_stats(s->a, "a");
		ft_stack_stats(s->b, "b");
		nl();
	}
}

void	nl(void)
{
	struct winsize	window;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
	ft_putxnl(window.ws_col, "_");
}
