/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:10:29 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 01:41:42 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	cmd_isempty(t_token **root)
{
	t_token	*t;

	t = *root;
	while (t)
	{
		if (t->name == T_WORD && ft_strlen(t->content))
			return (false);
		t = t->next;
	}
	return (true);
}

static void	flag_empty_token(t_token **root)
{
	t_token	*t;

	t = *root;
	while (t)
	{
		if (t->name == T_WORD && ft_strlen(t->content) == 0)
			t->name = T_DEL;
		t = t->next;
	}
}

int	set_is_empty(t_cmd *cmd)
{
	t_token	*cmd_copy;

	while (cmd)
	{
		flag_empty_token(&cmd->list_redir);
		cmd->isempty = false;
		if (cmd_isempty(&cmd->list_cmd))
			cmd->isempty = true;
		else
		{
			flag_empty_token(&cmd->list_cmd);
			cmd_copy = copy_lst_del(cmd->list_cmd);
			if (!cmd_copy)
				return (ERR_MALLOC);
			destroy_token_list(&cmd->list_cmd);
			cmd->list_cmd = cmd_copy;
		}
		cmd = cmd->next;
	}
	return (SUCCESS);
}

t_cmd	*create_pipeline(t_token *pipeline, t_env **env)
{
	t_cmd	*cmd;

	errno = 0;
	cmd = split_command(env_expander(pipeline, *env));
	if (!cmd)
		return (NULL);
	if (set_is_empty(cmd))
		return (NULL);
	if (concat_split(cmd) || init_wildcard(cmd) || prep(cmd, *env))
	{
		cmd_destructor(&cmd);
		return (NULL);
	}
	t_cmd_print(cmd, pipeline, true);
	return (cmd);
}
