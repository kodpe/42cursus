/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_parenthesis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:11:38 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/02 02:27:01 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*start_parenthesis(t_token *t)
{
	if (t->name == T_WHITESPACE)
		t = t->next;
	if (t->name == T_PARENTHESIS && t->content[0] == '(')
		return (t);
	return (NULL);
}

static t_token	*end_parenthesis(t_token *t)
{
	if (t->name == T_WHITESPACE)
		t = t->prev;
	if (t->name == T_PARENTHESIS && t->content[0] == ')')
		return (t);
	return (NULL);
}

t_token	*trim_parenthesis(t_token *t)
{
	t_token	*start;
	t_token	*end;
	t_token	*trimmed;

	if (!t)
		return (NULL);
	start = start_parenthesis(t);
	end = end_parenthesis(token_last(t));
	if (!start || !end)
	{
		trimmed = sublst(t, t, token_last(t));
		destroy_token_list(&t);
		return (trimmed);
	}
	trimmed = sublst(t, start->next, end->prev);
	if (!valid_parenthesis(trimmed, 0))
		trimmed = trim_parenthesis(trimmed);
	else
	{
		destroy_token_list(&trimmed);
		trimmed = sublst(t, start, end);
	}
	destroy_token_list(&t);
	return (trimmed);
}
