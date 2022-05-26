/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:28:11 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/16 20:28:11 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	secure_dup2(const int old_fd, const int new_fd)
{
	if (0 > old_fd || 0 > new_fd)
		return ;
	if (0 > dup2(old_fd, new_fd))
		perror("dup2");
}

/**
 * 	p->in ........ infile fd         (read file)
 *  p->out ....... outfile fd        (write file)
 * 
 *  p->pipe[2 * i - 2] next pipe in  (read end)
 *  p->pipe[2 * i + 1] next pipe out (write end)
 */
static void	dupdup(t_pipex *p, int i)
{
	if (i == 0)
	{
		secure_dup2(p->in, STDIN_FILENO);
		secure_dup2(p->pipe[2 * i + 1], STDOUT_FILENO);
	}
	else if (i == p->nbr_cmds - 1)
	{
		secure_dup2(p->pipe[2 * i - 2], STDIN_FILENO);
		secure_dup2(p->out, STDOUT_FILENO);
	}
	else
	{
		secure_dup2(p->pipe[2 * i - 2], STDIN_FILENO);
		secure_dup2(p->pipe[2 * i + 1], STDOUT_FILENO);
	}
}

static void	child_process(t_pipex *p, int i, char **envp)
{
	p->child = i;
	dupdup(p, i);
	close_all_fd(p);
	execute_cmd(p, i, envp);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*p;
	int		i;
	int		exitcode;

	p = create_pipex(ac, av, envp);
	pipex_info_create(p);
	i = 0;
	while (i < p->nbr_cmds)
	{
		if (i == 0 && p->in == CLOSE)
			i++;
		p->pid[i] = fork();
		if (0 > p->pid[i])
		{
			close_all_fd(p);
			destroy_pipex(p, E_FORK);
		}
		if (p->pid[i] == 0)
			child_process(p, i, envp);
		i++;
	}
	close_all_fd(p);
	exitcode = waitpid_status(p);
	destroy_pipex(p, exitcode);
}
