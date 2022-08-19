/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:12:05 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/29 21:55:23 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	valid_redir(t_token	*redir)
{
	int	i;

	i = 0;
	while (redir && redir->name != T_REDIR)
	{
		redir = redir->next;
		if (redir && redir->name == T_WORD)
			i++;
	}
	return (i);
}

static int	open_redir_out(t_token *redir, t_cmd *cmd)
{
	sc_close(&cmd->fd_out);
	if (!ft_strcmp(redir->content, ">"))
	{
		cmd->fd_out = open(redir->next->content, O_CWT, 0644);
		if (cmd->fd_out == -1)
		{
			if (err_msg_3_space_nl("mini-mishell: open_redir_out: ", \
				redir->next->content, strerror(errno)))
				return (-1);
			return (ERR_REDIR);
		}
	}
	else if (!ft_strcmp(redir->content, ">>"))
	{
		cmd->fd_out = open(redir->next->content, O_CWA, 0644);
		if (cmd->fd_out == -1)
		{
			if (err_msg_3_space_nl("mini-mishell: open_redir_out append: ", \
				redir->next->content, strerror(errno)))
				return (-1);
			return (ERR_REDIR);
		}
	}
	return (0);
}

static int	open_redir(t_token *redir, t_cmd *cmd)
{
	int	ret;

	if (redir->content[0] == '>')
		ret = open_redir_out(redir, cmd);
	else
		ret = open_redir_in(redir, cmd);
	return (ret);
}

int	set_redir(t_token *redir, t_cmd *cmd)
{
	int	ret;

	ret = 0;
	while (redir && ret != ERR_REDIR)
	{
		if (redir->name == T_REDIR)
		{
			if (redir->next
				&& redir->next->name != T_REDIR && !valid_redir(redir->next))
				ret = open_redir(redir, cmd);
			else if (redir->next && redir->name != T_REDIR)
			{
				ret = ERR_REDIR;
				if (err_msg_3(NAME, redir->next->content, ": ambiguous \
redirect\n"))
					return (-1);
			}
			else
			{
				ret = ERR_REDIR;
				err_msg("bash: ambiguous redirect\n");
			}
		}
		redir = redir->next;
	}
	return (ret);
}
