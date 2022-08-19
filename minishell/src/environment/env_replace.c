/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:46:49 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/28 15:49:11 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_replace(t_env **env, char *name, char *value)
{
	char	*var;
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			if (!tmp->value)
				return (ERR_MALLOC);
			return (SUCCESS);
		}
		tmp = tmp->next;
	}
	var = ft_strjointri(name, "=", value);
	if (!var)
		return (ERR_MALLOC);
	if (env_add(env, var))
		return (free(var), ERR_MALLOC);
	return (free(var), SUCCESS);
}
