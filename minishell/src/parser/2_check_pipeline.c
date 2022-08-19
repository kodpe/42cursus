/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_check_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:02:26 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/11 01:05:41 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * on prend une token lst avec juste les pipes, mots et, entrequotes
 */
static t_token	*copy_lst_pipeline(t_token *t)
{
	t_token	*root;

	root = NULL;
	while (t)
	{
		if (t->name == T_PIPE || t->name == T_ENTREQUOTE || t->name == T_WORD)
		{
			if (add_back(&root, new_token(t->name, t->content, t->size)))
			{
				destroy_token_list(&t);
				destroy_token_list(&root);
				return (NULL);
			}
		}
		t = t->next;
	}
	return (root);
}

/**
 * erreur si on a un pipe seul au debut ou a la fin de la pipeline
 * erreur si on a deux pipes cote a cote
 */
static int	check_pipes(t_token *t)
{
	while (t)
	{
		if (t->name == T_PIPE && (t->prev == NULL || t->next == NULL))
			break ;
		if (t->name == T_PIPE && t->next->name == T_PIPE)
			break ;
		t = t->next;
	}
	if (t)
	{
		message_erreur_2(t->content);
		return (1);
	}
	return (0);
}

/**
 * une pipeline ne peut pas contenir les tokens
 * T_FORBIDDEN (0) T_ANDOR (1) T_PARENTHESIS (2)
 */
static int	check_pipeline_integrity(t_token *t)
{
	while (t)
	{
		if (t->name < T_PIPE)
		{
			message_erreur_2(t->content);
			return (1);
		}
		t = t->next;
	}
	return (0);
}

/**
 * return 1 if token list contains a pipe, or 0
 */
static int	contains_a_pipe(t_token *t)
{
	while (t)
	{
		if (t->name == T_PIPE)
			return (1);
		t = t->next;
	}
	return (0);
}

int	valid_pipeline(t_token *pipeline)
{
	t_token	*pipeline_trimmed;

	if (check_pipeline_integrity(pipeline))
		return (2);
	if (!contains_a_pipe(pipeline))
		return (0);
	pipeline_trimmed = copy_lst_pipeline(pipeline);
	if (!pipeline_trimmed)
		return (ERR_MALLOC);
	if (check_pipes(pipeline_trimmed))
	{
		destroy_token_list(&pipeline_trimmed);
		return (2);
	}
	destroy_token_list(&pipeline_trimmed);
	return (0);
}
