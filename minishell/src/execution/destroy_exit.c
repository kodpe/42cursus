/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 07:05:14 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 21:49:03 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_exit(t_cmd *cmd, int exitcode)
{
	env_destroy(cmd->env);
	cmd_destructor(cmd->croot);
	exit(exitcode);
}
