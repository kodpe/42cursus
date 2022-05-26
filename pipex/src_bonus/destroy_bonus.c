/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:52:48 by sloquet           #+#    #+#             */
/*   Updated: 2022/05/25 14:02:20 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	destroy_heredoc(t_pipex *p)
{
	if (0 > p->child && p->heredoc)
		if (0 > unlink(TMP_FILE_HEREDOC))
			perror(TMP_FILE_HEREDOC);
}

static void	close_io(t_pipex *p)
{
	if (p->in > 0 && 0 > close(p->in))
		perror(p->in_name);
	p->in = CLOSE;
	if (p->out > 0 && 0 > close(p->out))
		perror(p->out_name);
	p->out = CLOSE;
}

static void	close_pipes(t_pipex *p)
{
	int	i;

	if (!p->pipe)
		return ;
	i = 0;
	while (i < p->pipe_tips)
	{
		if (p->pipe[i] > 0)
			if (0 > close(p->pipe[i]))
				perror("close pipe");
		i++;
	}
	p->pipe_tips = CLOSE;
}

void	close_all_fd(t_pipex *p)
{
	close_io(p);
	close_pipes(p);
}

void	destroy_pipex(t_pipex *p, int exitcode)
{
	close_all_fd(p);
	destroy_heredoc(p);
	free(p->in_name);
	free(p->out_name);
	ft_arfree(p->paths);
	free(p->pipe);
	free(p->pid);
	free(p);
	exit(exitcode);
}
