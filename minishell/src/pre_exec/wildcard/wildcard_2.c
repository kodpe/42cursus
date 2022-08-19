/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:39:44 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/28 13:25:17 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_wildcard	*set_flags(char *input)
{
	t_wildcard	*flag;

	flag = ft_calloc(sizeof(t_wildcard));
	if (!flag)
		return (NULL);
	if (input[0] != '*')
		flag->w_start_with = 1;
	if (input[ft_strlen(input) - 1] != '*')
		flag->w_end_with = 1;
	return (flag);
}

void	no_motif(t_token *file)
{
	while (file)
	{
		if (file->content[0] == '.')
			file->name = T_DEL;
		file = file->next;
	}
}

int	set_filter(char	*input, t_token	**file, char **tab)
{
	t_wildcard	*flag;

	flag = set_flags(input);
	if (!flag)
		return (ERR_MALLOC);
	if (ft_ar_size(tab) == 0)
		no_motif(*file);
	else
	{
		if (tab[0][0] != '.')
			no_motif(*file);
		valid_motif(*file, tab, flag);
	}
	free(flag);
	ft_arfree(tab);
	return (0);
}

int	get_motif(char	*input, t_token	**file)
{
	char		**tab;

	*file = NULL;
	if (get_files(file))
		return (ERR_MALLOC);
	if (!file)
	{
		*file = new_token(T_WORD, input, ft_strlen(input));
		if (!file)
			return (ERR_MALLOC);
		return (0);
	}
	tab = ft_split(input, '*');
	if (!tab)
		return (ERR_MALLOC);
	if (set_filter(input, file, tab))
	{
		ft_arfree(tab);
		return (ERR_MALLOC);
	}
	*file = filter_files(*file, input);
	if (!*file)
		return (ERR_MALLOC);
	return (0);
}
