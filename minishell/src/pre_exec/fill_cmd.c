/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:34:02 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/19 10:51:09 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fill_cmd_redir(t_token **p, t_token **redir_list)
{
	t_token	*tmp;

	tmp = *p;
	if (add_back(&(*redir_list), new_token((*p)->name, (*p)->content, 0)))
		return (ERR_MALLOC);
	*p = (*p)->next;
	if ((*p)->name == T_WHITESPACE)
		*p = (*p)->next;
	while (*p && ((*p)->name == T_WORD || (*p)->name == T_ENTREQUOTE))
	{
		tmp = *p;
		if (add_back(&(*redir_list), new_token((*p)->name, (*p)->content, 0)))
		{
			*p = tmp;
			return (ERR_MALLOC);
		}
		*p = (*p)->next;
	}
	*p = tmp;
	return (0);
}

int	fill_cmd(t_cmd **cmd, t_token *p)
{
	t_cmd	*root;

	root = *cmd;
	while (p)
	{
		if (p->name == T_PIPE)
			*cmd = (*cmd)->next;
		else if (p->name == T_REDIR)
		{
			if (fill_cmd_redir(&p, &(*cmd)->list_redir))
			{
				*cmd = root;
				return (ERR_MALLOC);
			}
		}
		else if (add_back(&(*cmd)->list_cmd, new_token(p->name, p->content, 0)))
		{
			*cmd = root;
			return (ERR_MALLOC);
		}
		p = p->next;
	}
	*cmd = root;
	return (0);
}
