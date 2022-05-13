/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:09:40 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/05 17:06:47 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_index_upper_tab(int *tab, int siz)
{
	int	upper;

	upper = 0;
	while (siz > 0)
	{
		siz--;
		if (tab[siz] > tab[upper])
			upper = siz;
	}
	return (upper);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	index_upper;

	while (size > 0)
	{
		size--;
		index_upper = ft_index_upper_tab(tab, (size + 1));
		ft_swap(&tab[size], &tab[index_upper]);
	}
}
