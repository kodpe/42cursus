/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:15:35 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/11 01:18:08 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parenthesis_is_closed(t_token *tolkien)
{
	int	i;

	i = 0;
	while (tolkien)
	{
		if (tolkien->name == T_PARENTHESIS)
		{
			if (tolkien->content[0] == '(')
				i++;
			if (tolkien->content[0] == ')')
				i--;
			if (i < 0)
				return (2);
		}
		tolkien = tolkien->next;
	}
	if (i == 0)
		return (0);
	else
		return (2);
}

static t_token	*copy_lst_parenthesis(t_token *t)
{
	t_token	*root;

	root = NULL;
	while (t)
	{
		if (t->name != T_WHITESPACE)
		{
			if (add_back(&root, new_token(t->name, t->content, t->size)))
			{
				destroy_token_list(&root);
				return (NULL);
			}
		}
		t = t->next;
	}
	return (root);
}

static int	check_parenthesis_integrity(t_token *t, int show)
{
	while (t)
	{
		if (t->name == T_PARENTHESIS && t->content[0] == '(')
		{
			if (check_open(t, show))
				return (2);
			if (t->next && t->next->name == T_ANDOR)
				return (2);
			if (t->prev)
				if (t->prev->name != T_PARENTHESIS && t->prev->name != T_ANDOR)
					return (2);
		}
		if (t->name == T_PARENTHESIS && t->content[0] == ')')
		{
			if (check_close(t, show))
				return (2);
			if (t->prev->name == T_ANDOR)
				return (2);
			if (t->next)
				if (t->next->name != T_PARENTHESIS && t->next->name != T_ANDOR)
					return (2);
		}
		t = t->next;
	}
	return (0);
}

int	valid_parenthesis(t_token *t, int show)
{
	t_token	*root;

	if (parenthesis_is_closed(t))
	{
		while (t && t->name != T_PARENTHESIS)
			t = t->next;
		message_erreur(t->content, show);
		return (2);
	}
	root = copy_lst_parenthesis(t);
	if (!root)
		return (ERR_MALLOC);
	if (check_parenthesis_integrity(root, show))
	{
		destroy_token_list(&root);
		return (2);
	}
	destroy_token_list(&root);
	return (0);
}
