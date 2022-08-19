/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_spllit_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:52:30 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/28 15:58:31 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	split_token_redir(t_token **t, t_token **new)
{
	if (add_back(new, new_token((*t)->name, (*t)->content, (*t)->size)))
		return (ERR_MALLOC);
	*t = (*t)->next;
	if ((*t)->name == T_WHITESPACE)
		*t = (*t)->next;
	while (*t && (*t)->name != T_WHITESPACE)
	{
		if (add_back(new, new_token((*t)->name, (*t)->content, (*t)->size)))
			return (ERR_MALLOC);
		*t = (*t)->next;
	}
	if (*t)
	{
		if (add_back(new, new_token((*t)->name, (*t)->content, (*t)->size)))
			return (ERR_MALLOC);
	}
	return (0);
}

t_token	*env_split_token(t_token *t, t_tolkien name, char sep)
{
	t_token	*new;

	new = NULL;
	while (t)
	{
		if (t->name == T_REDIR)
		{
			if (split_token_redir(&t, &new))
				break ;
		}
		else if (t->name == name && ft_strchr(t->content, sep))
		{
			if (add_back(&new, token_convert(ft_split(t->content, sep))))
				break ;
		}
		else if (add_back(&new, new_token(t->name, t->content, t->size)))
			break ;
		if (t)
			t = t->next;
	}
	if (t)
		return (destroy_token_list(&new), NULL);
	return (new);
}
