/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redir_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:04:21 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/29 21:41:07 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_file(char *str, t_cmd *cmd)
{
	cmd->fd_in = open(str, O_RDONLY, 0644);
	if (cmd->fd_in == -1)
	{
		if (err_msg_3_space_nl("mini-mishell: open_file: ", \
			str, strerror(errno)))
			return (-1);
		return (ERR_REDIR);
	}
	return (0);
}

int	open_here_doc(t_token *redir, t_cmd *cmd)
{
	if (open_file(redir->next->content, cmd))
	{
		unlink_sc(redir->next->content);
		return (ERR_REDIR);
	}
	unlink_sc(redir->next->content);
	return (0);
}

int	is_last_here_doc(t_token *redir)
{
	while (redir)
	{
		if (redir->name == T_REDIR && !ft_strcmp(redir->content, "<<"))
			return (0);
		redir = redir->next;
	}
	return (1);
}

int	open_redir_in(t_token *redir, t_cmd *cmd)
{
	sc_close(&cmd->fd_in);
	if (!ft_strcmp(redir->content, "<"))
	{
		if (open_file(redir->next->content, cmd))
			return (ERR_REDIR);
	}
	else if (!ft_strcmp(redir->content, "<<"))
	{
		if (is_last_here_doc(redir->next) && open_here_doc(redir, cmd))
			return (ERR_REDIR);
	}
	return (0);
}
