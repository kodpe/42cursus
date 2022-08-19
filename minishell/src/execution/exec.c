/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:39:19 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/28 14:08:07 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	pipeline_size(t_cmd *cmd)
{
	size_t	n;

	n = 0;
	while (cmd)
	{
		cmd = cmd->next;
		n++;
	}
	return (n);
}

void	unlink_for_all_cmd(t_cmd *cmd)
{
	while (cmd)
	{
		unlink_last_here_doc(cmd->list_redir);
		cmd = cmd->next;
	}
}

static void	exit_error_fork(pid_t *pid, t_cmd *cmd)
{
	perror("exec:fork()");
	wait_all_child(pid, cmd->pos - 1);
	unlink_for_all_cmd(*(cmd)->croot);
	sc_2close(&cmd->fd_in, &cmd->fd_out);
	if (cmd->next)
		sc_close(&cmd->next->fd_in);
}

int	exec(t_cmd *cmd)
{
	size_t	nb_fork;
	pid_t	*pid;

	nb_fork = pipeline_size(cmd);
	pid = create_pidtab(nb_fork);
	if (!pid)
		return (unlink_for_all_cmd(*(cmd)->croot), -1);
	signal(SIGINT, SIG_IGN);
	while (cmd)
	{
		cmd->pid = pid;
		if (cmd->next && 0 > one_pipe(cmd, pid))
			return (ERR_PIPE);
		pid[cmd->pos] = fork();
		if (0 > pid[cmd->pos])
			return (exit_error_fork(pid, cmd), -1);
		if (pid[cmd->pos] == 0)
			child_process(cmd);
		else
			sc_2close(&cmd->fd_in, &cmd->fd_out);
		cmd = cmd->next;
	}
	return (pipeline_exitcode(pid, nb_fork));
}

/*
db(FI, LN, "parent apres ALL FORK, clique pour dup");
for (size_t i = 0; i < nb_fork; i++)
	kill(pid[i], 18);
db(FI, LN, "parent apres ALL dup, clique pour close all fork");
for (size_t i = 0; i < nb_fork; i++)
	kill(pid[i], 18);
db(FI, LN, "parent apres ALL close, clique pour exit all fork");
for (size_t i = 0; i < nb_fork; i++)
	kill(pid[i], 18);
*/
