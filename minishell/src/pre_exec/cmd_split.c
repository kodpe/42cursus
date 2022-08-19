/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:29:01 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/28 19:12:50 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	pipe_number(t_token *pipeline)
{
	int	i;

	i = 0;
	while (pipeline)
	{
		if (pipeline->name == T_PIPE)
			i++;
		pipeline = pipeline->next;
	}
	return (i);
}

t_cmd	*split_command(t_token *pipeline)
{
	t_cmd	*cmd;

	if (!pipeline)
		return (NULL);
	cmd = create_cmd(pipe_number(pipeline));
	if (!cmd)
	{
		destroy_token_list(&pipeline);
		return (NULL);
	}
	if (fill_cmd(&cmd, pipeline))
	{
		destroy_token_list(&pipeline);
		cmd_destructor(&cmd);
		return (NULL);
	}
	destroy_token_list(&pipeline);
	return (cmd);
}
