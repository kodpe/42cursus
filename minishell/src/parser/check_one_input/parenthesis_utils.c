/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.2_parenthesis_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:39:00 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/01 16:40:16 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_parenthesis_empty(t_token *t)
{
	while (t && t->next)
	{
		if (t->name == T_ANDOR)
			return (0);
		else if (t->name == T_PARENTHESIS && t->content[0] == ')')
			return (2);
		t = t->next;
	}
	return (2);
}

int	check_parenthesis_prev(t_token *t)
{
	while (t && t->prev)
	{
		if (t->name == T_ANDOR)
			return (0);
		else if (t->name != T_PARENTHESIS)
			return (2);
		t = t->prev;
	}
	return (0);
}

int	check_parenthesis_next(t_token *t)
{
	while (t && t->next)
	{
		if (t->name == T_ANDOR)
			return (0);
		else if (t->name != T_PARENTHESIS)
			return (2);
		t = t->next;
	}
	return (0);
}

int	check_open(t_token *t, int show)
{
	if (check_parenthesis_empty(t))
	{
		message_err_sous_shell();
		return (2);
	}
	else if (check_parenthesis_prev(t))
	{
		while (t->name == T_PARENTHESIS && t->prev)
			t = t->prev;
		message_erreur(t->content, show);
		return (2);
	}
	return (0);
}

int	check_close(t_token *t, int show)
{
	if (check_parenthesis_next(t))
	{
		while (t->name == T_PARENTHESIS)
			t = t->next;
		message_erreur(t->content, show);
		return (2);
	}
	return (0);
}
