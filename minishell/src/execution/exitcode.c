/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:12:56 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 21:15:23 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	show_child_exitcode(pid_t pid, int exitcode)
{
	if (!SHOW_EXITCODE)
		return ;
	c_magenta();
	ft_dprintf(2, "[%d] exitcode: %d\n", pid, exitcode);
	c_reset();
}

static int	child_exitcode(pid_t pid, int *ctrl_c)
{
	int	status;
	int	exitcode;

	exitcode = 1;
	if (0 > waitpid(pid, &status, 0))
		perror("waitpid_status:waitpid()");
	if (WIFEXITED(status))
		exitcode = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		exitcode = 128 + WTERMSIG(status);
		if (exitcode == 130 && *ctrl_c == 0)
		{
			write(2, "\n", 1);
			*ctrl_c = 1;
			g_g = 1;
		}
	}
	show_child_exitcode(pid, exitcode);
	return (exitcode);
}

int	pipeline_exitcode(pid_t *pid, size_t nb_fork)
{
	int		exitcode;
	int		ctrl_c;
	size_t	i;

	exitcode = 0;
	ctrl_c = 0;
	i = 0;
	while (i < nb_fork)
	{
		exitcode = child_exitcode(pid[i], &ctrl_c);
		i++;
	}
	free(pid);
	signal(SIGINT, sighandler);
	if (exitcode == 131)
		write(2, "Quit (core dumped)\n", 20);
	return (exitcode);
}
