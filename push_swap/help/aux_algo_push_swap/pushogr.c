/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushogr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:33:47 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 05:34:08 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * tmp function, push n sorted to a from grp of b
 */

static void	pushsogr(t_two *s, int grp)
{
	int	i;
	int	imax;
	int	valmax;
	int	rb_count;

	while (grp)
	{
		imax = s->b->top;
		valmax = s->b->t[ft_stack_min(s->b)];
		i = 0;
		while (i < grp)
		{
			if (s->b->t[s->b->top - i] > valmax)
			{
				imax = s->b->top - i;
				valmax = s->b->t[imax];
			}
			i++;
		}
		rb_count = s->b->top - imax;
		rb(rb_count, s);
		pa(1, s);
		rrb(rb_count, s);
		grp--;
	}
}
