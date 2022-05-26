/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:00:47 by sloquet           #+#    #+#             */
/*   Updated: 2022/05/25 16:00:50 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex_info_create(t_pipex *p)
{
	if (!PIPEX_INFO)
		return ;
	if (PRINT_PATHS && p->paths)
	{
		ft_fprintf(2, "\np->paths %p\n", p->paths);
		ft_putarray_fd(p->paths, 2);
	}
	ft_fprintf(2, "FDin %d  FDout %d  heredoc %d\n", p->in, p->out, p->heredoc);
	ft_fprintf(2, "nbr_cmds %d  cmd 0: %s\n", p->nbr_cmds, *p->cmds);
}

int	pipex_info_child(t_pipex *p, int i, int status)
{
	int	code;

	code = -42;
	if (WIFEXITED(status))
		code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		code = 128 + WTERMSIG(status);
	if (!PIPEX_INFO)
		return (code);
	ft_fprintf(2, "\nparent has waited for child %d: %d", i, p->pid[i]);
	ft_fprintf(2, " cmd: %s\n", p->cmds[i]);
	ft_fprintf(2, "exitcode/signal: %d\n", code);
	return (code);
}

int	waitpid_status(t_pipex *p)
{
	int	status;
	int	exitcode;
	int	i;

	exitcode = 0;
	i = 0;
	while (i < p->nbr_cmds)
	{
		if (i == 0 && p->in == CLOSE)
			i++;
		status = -1;
		if (0 > waitpid(p->pid[i], &status, 0))
			perror("waitpid");
		else
			exitcode = pipex_info_child(p, i, status);
		i++;
	}
	return (exitcode);
}
