/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:50:58 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/29 06:21:30 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*remove_quote(char *str)
{
	char	*copy;

	copy = ft_substr(str, 1, ft_strlen(str) - 2);
	free(str);
	if (!copy)
		return (NULL);
	return (copy);
}

static int	remove_all_quote(t_token *t)
{
	while (t)
	{
		if (t->name == T_ENTREQUOTE)
		{
			t->content = remove_quote(t->content);
			if (!t->content)
				return (ERR_MALLOC);
		}
		t = t->next;
	}
	return (0);
}

static int	link_word_quote(t_token *t)
{
	char	*copy;

	if (t->prev && t->prev->name == T_WORD)
	{
		copy = ft_strjoin(t->prev->content, t->content);
		if (!copy)
			return (ERR_MALLOC);
		free(t->content);
		t->content = copy;
		t->prev->name = T_DEL;
		t->is_concated = 1;
	}
	if (t->name == T_ENTREQUOTE && ft_strchr(t->content, '*'))
		t->is_concated = 1;
	t->name = T_WORD;
	return (0);
}

static int	join_quote_word(t_token *t)
{
	while (t)
	{
		if (t->name == T_ENTREQUOTE || t->name == T_WORD)
		{
			if (t->name == T_ENTREQUOTE)
				t->is_concated = 1;
			if (link_word_quote(t))
				return (ERR_MALLOC);
		}
		t = t->next;
	}
	return (0);
}

t_token	*concatene(t_token *t)
{
	t_token	*copy;

	if (remove_all_quote(t))
		return (NULL);
	if (join_quote_word(t))
		return (NULL);
	copy = copy_lst_del_concat(t);
	if (!copy)
		return (NULL);
	return (copy);
}
