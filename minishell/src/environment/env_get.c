/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 03:29:20 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/27 03:07:11 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_get_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (ft_strldup(str, i + 1));
}

char	*env_get_value(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (!str[i])
		return (ft_strdup(""));
	return (ft_strdup(&str[i + 1]));
}

char	*env_get(t_env *env, char *name)
{
	if (!name)
		return (NULL);
	while (env)
	{
		if (!ft_strcmp(env->name, name))
			return (ft_strdup(env->value));
		env = env->next;
	}
	return (ft_strdup(""));
}

bool	env_exist(t_env *env, char *name)
{
	while (env)
	{
		if (!ft_strcmp(env->name, name))
			return (true);
		env = env->next;
	}
	return (false);
}
