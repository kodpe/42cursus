/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:55:16 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/30 09:52:59 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	do_dup(t_cmd *cmd)
{
	if (cmd->fd_in != -1)
		sc_dup2(cmd->fd_in, STDIN_FILENO);
	if (cmd->fd_out != -1)
		sc_dup2(cmd->fd_out, STDOUT_FILENO);
}

static void	close_child_dup(t_cmd *cmd)
{
	sc_2close(&cmd->fd_in, &cmd->fd_out);
	if (cmd->next)
		sc_close(&cmd->next->fd_in);
}

static	int	is_empty_and_not_concated(t_token *root)
{
	t_token	*t;

	t = root;
	while (t)
	{
		if (ft_strlen(t->content) || t->is_concated)
			return (0);
		t = t->next;
	}
	return (1);
}

static void	execute_cmd(t_cmd *cmd)
{
	int	exitcode;

	if (!cmd->argv || !cmd->argv[0] || is_empty_and_not_concated(cmd->list_cmd))
		destroy_exit(cmd, 0);
	if (cmd->isbuiltin)
	{
		exitcode = execute_one_builtin(cmd, cmd->argv[0], cmd->env);
		destroy_exit(cmd, exitcode);
	}
	cmd->pathname = pathfinder(cmd->argv[0], cmd->path, &exitcode);
	if (!cmd->pathname)
		exitcode = 255;
	if (exitcode)
		destroy_exit(cmd, exitcode);
	execve(cmd->pathname, cmd->argv, cmd->envp);
	perror(cmd->pathname);
	destroy_exit(cmd, EXIT_CANT_EXEC);
}

void	child_process(t_cmd *cmd)
{
	int	ret_redir;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	errno = 0;
	btree_destroy(cmd->tree);
	free(cmd->pid);
	ret_redir = set_redir(cmd->list_redir, cmd);
	if (ret_redir)
	{
		close_child_dup(cmd);
		env_destroy(cmd->env);
		cmd_destructor(cmd->croot);
		exit(ret_redir);
	}
	do_dup(cmd);
	close_child_dup(cmd);
	execute_cmd(cmd);
}
