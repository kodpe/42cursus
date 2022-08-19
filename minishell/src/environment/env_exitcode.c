/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exitcode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:57:22 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 07:13:35 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_update_exitcode(t_env *env, int exitcode)
{
	if (exitcode == ERR_PIPE)
		exitcode = EXIT_ERR_PIPE;
	if (g_g == 1)
	{
		exitcode = 130;
		g_g = 0;
	}
	while (env)
	{
		if (!ft_strcmp(env->name, OLD_EXITCODE))
		{
			free(env->value);
			env->value = ft_itoa(exitcode);
			if (!env->value)
				return (ERR_MALLOC);
			return (SUCCESS);
		}
		env = env->next;
	}
	env->value = NULL;
	return (SUCCESS);
}

int	env_old_exitcode(t_env *env)
{
	char	*tmp;
	int		exitcode;

	tmp = env_get(env, OLD_EXITCODE);
	if (!tmp)
		return (ERR_MALLOC);
	exitcode = ft_atoi(tmp);
	free(tmp);
	return (exitcode);
}
