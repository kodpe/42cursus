/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:07:15 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/28 19:16:21 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	concat_arg(t_cmd *cmd)
{
	t_token	*concated_arg;

	if (cmd->list_cmd)
	{
		concated_arg = concatene(cmd->list_cmd);
		if (!concated_arg)
			return (ERR_MALLOC);
		destroy_token_list(&cmd->list_cmd);
		cmd->list_cmd = concated_arg;
	}
	return (0);
}

int	concat_redir(t_cmd *cmd)
{
	t_token	*concated_redir;

	if (cmd->list_redir)
	{
		concated_redir = concatene(cmd->list_redir);
		if (!concated_redir)
			return (ERR_MALLOC);
		destroy_token_list(&cmd->list_redir);
		cmd->list_redir = concated_redir;
	}
	return (0);
}

int	concat_split(t_cmd *cmd)
{
	while (cmd)
	{
		if (concat_arg(cmd))
			return (ERR_MALLOC);
		if (concat_redir(cmd))
			return (ERR_MALLOC);
		cmd = cmd->next;
	}	
	return (0);
}
