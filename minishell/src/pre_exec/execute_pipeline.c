/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:18:14 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/29 17:25:08 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	to_free(t_cmd *cmd, t_cmd **croot, t_btree **tree, t_env **env)
{
	while (cmd)
	{
		cmd->croot = croot;
		cmd->tree = tree;
		cmd->env = env;
		cmd = cmd->next;
	}
}

static int	builtin(t_env **env, t_cmd *cmd)
{
	int		exitcode;

	if (set_redir(cmd->list_redir, cmd))
		return (1);
	save_i_o(cmd);
	exitcode = execute_one_builtin(cmd, cmd->argv[0], env);
	res_i_o(cmd);
	return (exitcode);
}

int	execute_pipeline(t_token *pipeline, t_env **env, t_btree **root)
{
	int		exitcode;
	t_cmd	*cmd;

	cmd = create_pipeline(pipeline, env);
	if (!cmd)
		return (-1);
	to_free(cmd, &cmd, root, env);
	if (here_doc_for_each_cmd(cmd))
	{
		cmd_destructor(cmd->croot);
		return (-1);
	}
	if (g_g)
	{
		cmd_destructor(cmd->croot);
		return (130);
	}
	if (cmd->isbuiltin && !cmd->next)
		exitcode = builtin(env, cmd);
	else
		exitcode = exec(cmd);
	cmd_destructor(cmd->croot);
	return (exitcode);
}
