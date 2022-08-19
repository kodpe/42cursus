/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:37:43 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/29 17:09:15 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define IS_NOT_REDIR 0
#define IS_REDIR 1

int	expand_wildcard(t_token **ptr, int is_redir)
{
	t_token	*expand;

	if (get_motif((*ptr)->content, &expand))
		return (ERR_MALLOC);
	if (SHOW_WILDCARD)
		print_token_list_one_line(expand, "FILE WITH MOTIF", c_cyan);
	if (is_redir && expand->next && expand->next->next)
	{
		free(expand->content);
		expand->content = ft_strdup((*ptr)->content);
	}
	*ptr = add_token_list(ptr, expand);
	return (0);
}

int	apply_wildcard(t_token *ptr, int is_redir)
{
	while (ptr)
	{
		if (ptr->name == T_REDIR && !ft_strncmp(ptr->content, "<<", 2))
			ptr = ptr->next;
		else if (ptr->name == T_WORD)
		{	
			if (ft_strchr(ptr->content, '*') && !ptr->is_concated)
			{
				if (expand_wildcard(&ptr, is_redir))
					return (ERR_MALLOC);
			}
		}
		if (ptr)
			ptr = ptr->next;
	}
	return (0);
}

int	del_w_fix(t_token **t)
{
	t_token	*root;

	if (!*t)
		return (0);
	root = copy_lst_del_concat(*t);
	if (!root)
		return (ERR_MALLOC);
	destroy_token_list(t);
	*t = root;
	return (0);
}

int	init_wildcard(t_cmd	*cmd)
{
	while (cmd)
	{
		if (cmd->list_cmd)
		{
			if (apply_wildcard(cmd->list_cmd, IS_NOT_REDIR))
				return (ERR_MALLOC);
		}
		if (SHOW_DEBUG_WILDCARD)
			print_token_list(cmd->list_cmd, "VERIF PTR_CMD");
		if (apply_wildcard(cmd->list_redir, IS_REDIR))
			return (ERR_MALLOC);
		if (del_w_fix(&cmd->list_cmd))
			return (ERR_MALLOC);
		if (del_w_fix(&cmd->list_redir))
			return (ERR_MALLOC);
		cmd = cmd->next;
	}
	return (0);
}
