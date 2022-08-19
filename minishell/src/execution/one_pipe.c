/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:20:19 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/27 15:32:57 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define PIPE_IN 1
#define PIPE_OUT 0

static void	show_pipe(int *pptab, int pos)
{
	if (!pptab)
		return ;
	ft_dprintf(2, "            ____\n");
	ft_dprintf(2, "PIPE %02d: %02d)____( %02d \n", pos, pptab[1], pptab[0]);
}

int	one_pipe(t_cmd *cmd, pid_t *pid)
{
	int	pipetab[2];

	if (0 > pipe(pipetab))
	{
		perror("do_pipe: pipe");
		sc_close(&cmd->fd_in);
		wait_all_child(pid, cmd->pos - 1);
		unlink_for_all_cmd(*(cmd)->croot);
		return (ERR_PIPE);
	}
	if (SHOW_PIPE)
		show_pipe(pipetab, cmd->pos);
	cmd->fd_out = pipetab[PIPE_IN];
	cmd->next->fd_in = pipetab[PIPE_OUT];
	return (SUCCESS);
}
