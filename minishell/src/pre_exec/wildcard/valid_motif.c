/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_motif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:42:48 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/07 17:28:33 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	start_with(char *big, char **tab)
{
	if (!ft_strnstr(big, tab[0], ft_strlen(tab[0])))
		return (1);
	return (0);
}

int	end_with(char *big, char **tab)
{
	char	*s;

	s = tab[ft_ar_size(tab) - 1];
	if (!ft_strnrstr(big, s, ft_strlen(s)))
		return (1);
	return (0);
}

int	middle_with(char *big, char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		big = ft_strnstr2(big, tab[i], ft_strlen(big));
		if (!big)
			return (1);
		i++;
	}
	return (0);
}

int	valid_file(char *big, char **tab, t_wildcard *flag)
{
	if (flag->w_start_with)
	{
		if (start_with(big, tab))
			return (1);
	}
	if (flag->w_end_with)
	{
		if (end_with(big, tab))
			return (1);
	}
	if (middle_with(big, tab))
		return (1);
	return (0);
}

void	valid_motif(t_token *f, char **tab, t_wildcard *flag)
{
	while (f)
	{
		if (valid_file(f->content, tab, flag))
			f->name = T_DEL;
		f = f->next;
	}
}
