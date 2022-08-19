/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:52:33 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/03 02:43:14 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_del(t_env **env, char *name)
{
	t_env	*tmp;

	while (*env && (*env)->next)
	{
		if (!ft_strcmp((*env)->next->name, name))
		{
			tmp = (*env)->next->next;
			free((*env)->next->name);
			free((*env)->next->value);
			free((*env)->next);
			(*env)->next = tmp;
			return ;
		}
		*env = (*env)->next;
	}
}
