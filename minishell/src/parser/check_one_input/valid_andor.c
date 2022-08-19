/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_andor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:02:26 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/11 01:59:43 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	no_andor(t_token *t)
{
	while (t)
	{
		if (t->name == T_ANDOR)
			return (0);
		t = t->next;
	}
	return (1);
}

static t_token	*copy_lst_andor(t_token *t)
{
	t_token	*root;

	root = NULL;
	while (t)
	{
		if (t->name == T_ANDOR || t->name == T_ENTREQUOTE || t->name == T_WORD)
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

static int	is_it_andor_valid(t_token *t)
{
	int	error;

	error = 0;
	while (t)
	{
		if (t->name == T_ANDOR && t->prev == NULL)
			error++;
		else if (t->name == T_ANDOR && t->next == NULL)
			error++;
		else if (t->name == T_ANDOR && t->prev->name == T_ANDOR)
			error++;
		else if (t->name == T_ANDOR && t->next->name == T_ANDOR)
			error++;
		if (error)
		{
			message_erreur(t->content, 1);
			return (2);
		}
		t = t->next;
	}
	return (0);
}

int	valid_andor(t_token *t)
{
	t_token	*root;
	int		err;

	if (no_andor(t))
		return (0);
	root = copy_lst_andor(t);
	if (!root)
		return (ERR_MALLOC);
	err = is_it_andor_valid(root);
	destroy_token_list(&root);
	if (err)
		return (2);
	return (0);
}
