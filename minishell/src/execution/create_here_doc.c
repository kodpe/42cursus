/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:07:10 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/28 23:31:07 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_here_doc(t_token *redir, t_cmd *cmd, char *str, int oui)
{
	sc_close(&cmd->fd_in);
	signal(SIGINT, sighandler);
	sc_dup2(oui, 0);
	sc_close(&oui);
	free(redir->next->content);
	redir->next->content = str;
	if (g_g)
	{
		unlink_sc(str);
		write(2, "\n", 1);
	}
}

int	create_here_doc(t_token *redir, t_cmd *cmd)
{
	char	*str;
	int		oui;

	str = get_tmp_file();
	if (!str)
		return (ERR_MALLOC);
	cmd->fd_in = open(str, O_CWT, 0644);
	if (cmd->fd_in == -1)
	{
		perror("mini-mishell: create_here_doc");
		return (free(str), ERR_MALLOC);
	}
	oui = sc_dup(0);
	signal(SIGINT, sig_heredoc);
	if (redir->next && fill_here_doc(cmd->fd_in, redir->next->content,
			*(cmd)->env, redir->next->is_concated))
	{
		sc_close(&cmd->fd_in);
		unlink_sc(str);
		return (free(str), ERR_MALLOC);
	}
	close_here_doc(redir, cmd, str, oui);
	return (0);
}

int	here_doc_for_each_redir(t_token *redir, t_cmd *cmd)
{
	char	*prev_here_doc;

	prev_here_doc = NULL;
	while (redir && !g_g)
	{
		if (redir->name == T_REDIR && !ft_strcmp(redir->content, "<<"))
		{
			if (prev_here_doc)
				unlink_sc(prev_here_doc);
			if (create_here_doc(redir, cmd))
				return (ERR_MALLOC);
			prev_here_doc = redir->next->content;
		}
		redir = redir->next;
	}
	return (0);
}

void	unlink_last_here_doc(t_token *redir)
{
	redir = token_last(redir);
	while (redir)
	{
		if (redir->name == T_REDIR && !ft_strcmp(redir->content, "<<"))
		{
			unlink_sc(redir->next->content);
			break ;
		}
		redir = redir->prev;
	}
}

int	here_doc_for_each_cmd(t_cmd *cmd)
{
	if (cmd->list_redir && here_doc_for_each_redir(cmd->list_redir, cmd))
		return (1);
	if (g_g)
		return (0);
	if ((cmd->next && here_doc_for_each_cmd(cmd->next)) || g_g)
	{
		unlink_last_here_doc(cmd->list_redir);
		if (g_g)
			return (0);
		return (1);
	}
	return (0);
}
