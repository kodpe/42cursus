/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_res_io.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:09:22 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/28 16:11:37 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_i_o(t_cmd *cmd)
{
	if (cmd->fd_in > 0)
	{
		cmd->save_stdin = sc_dup(STDIN_FILENO);
		sc_dup2(cmd->fd_in, STDIN_FILENO);
	}
	if (cmd->fd_out > 0)
	{
		cmd->save_stdout = sc_dup(STDOUT_FILENO);
		sc_dup2(cmd->fd_out, STDOUT_FILENO);
	}
}

void	res_i_o(t_cmd *cmd)
{
	if (cmd->fd_in > 0)
	{
		sc_dup2(cmd->save_stdin, STDIN_FILENO);
		sc_close(&cmd->save_stdin);
		sc_close(&cmd->fd_in);
	}
	if (cmd->fd_out > 0)
	{
		sc_dup2(cmd->save_stdout, STDOUT_FILENO);
		sc_close(&cmd->save_stdout);
		sc_close(&cmd->fd_out);
	}
}
