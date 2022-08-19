/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_check_cmd_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:02:26 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/11 01:06:32 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * on prend une token lst avec juste les pipes, mots et, entrequotes
 */
static t_token	*copy_lst_command_trim(t_token *t)
{
	t_token	*root;

	root = NULL;
	while (t)
	{
		if (t->name == T_REDIR || t->name == T_ENTREQUOTE || t->name == T_WORD)
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
 * erreur si on trouve une redir sans token word ou entrequote a sa droite
 */
static int	check_redir_without_filename(t_token *t)
{
	while (t)
	{
		if (t->name == T_REDIR && t->next == NULL)
			break ;
		if (t->name == T_REDIR && t->next->name == T_REDIR)
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
 * une command ne peut pas contenir les tokens
 * T_FORBIDDEN (0) T_ANDOR (1) T_PARENTHESIS (2) T_PIPE (3)
 */
static int	check_command_integrity(t_token *t)
{
	while (t)
	{
		if (t->name < T_WHITESPACE)
		{
			message_erreur_2(t->content);
			return (1);
		}
		t = t->next;
	}
	return (0);
}

static int	valid_command(t_token *command)
{
	t_token	*command_trimmed;

	if (check_command_integrity(command))
	{
		destroy_token_list(&command);
		return (2);
	}
	command_trimmed = copy_lst_command_trim(command);
	destroy_token_list(&command);
	if (check_redir_without_filename(command_trimmed))
	{
		destroy_token_list(&command_trimmed);
		return (2);
	}
	destroy_token_list(&command_trimmed);
	return (0);
}

int	valid_cmd(t_token *pipeline)
{
	t_token	*t;
	t_token	*end;
	t_token	*cmd;

	t = pipeline;
	while (t)
	{
		end = cmd_end(t);
		cmd = sublst(pipeline, t, end);
		if (!cmd)
			return (ERR_MALLOC);
		if (valid_command(cmd))
			return (2);
		if (!end->next)
			t = NULL;
		else
			t = end->next->next;
	}
	return (0);
}
