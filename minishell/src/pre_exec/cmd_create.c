/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:42:51 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/25 15:23:50 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)ft_calloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->fd_in = -1;
	cmd->fd_out = -1;
	return (cmd);
}

t_cmd	*create_cmd(int i)
{
	t_cmd	*new;
	t_cmd	*root;

	root = new_cmd();
	if (!root)
		return (NULL);
	while (i)
	{
		new = new_cmd();
		if (!new)
		{
			cmd_destructor(&root);
			return (NULL);
		}
		new->next = root;
		root = new;
		i--;
	}
	return (root);
}
