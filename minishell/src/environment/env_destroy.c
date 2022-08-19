/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:48:01 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/03 02:44:09 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_destroy(t_env **env)
{
	t_env	*tmp;

	if (env)
	{
		while (*env)
		{
			tmp = (*env)->next;
			free((*env)->name);
			free((*env)->value);
			free(*env);
			*env = tmp;
		}
	}
	*env = NULL;
}
