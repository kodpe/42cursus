/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_destructor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:40:44 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/19 11:16:30 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_destructor(t_cmd **cmd)
{
	t_cmd	*temp;

	if (!cmd)
		return ;
	while (*cmd)
	{
		temp = (*cmd)->next;
		destroy_token_list(&(*cmd)->list_cmd);
		destroy_token_list(&(*cmd)->list_redir);
		free((*cmd)->pathname);
		ft_arfree((*cmd)->argv);
		ft_arfree((*cmd)->envp);
		ft_arfree((*cmd)->path);
		free(*cmd);
		*cmd = temp;
	}
	*cmd = NULL;
}
