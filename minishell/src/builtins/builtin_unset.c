/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:42:46 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 23:03:01 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

static void	env_unset(t_env **env_root, char *name)
{
	t_env	*env;
	t_env	*tmp;

	env = *env_root;
	while (env && env->next)
	{
		if (!ft_strcmp(env->next->name, name))
		{
			tmp = env->next->next;
			free(env->next->name);
			free(env->next->value);
			free(env->next);
			env->next = tmp;
			return ;
		}
		env = env->next;
	}
}

static int	bt_error(char *str)
{
	if (err_msg_3("minishell: unset: `", str, "': not a valid identifier\n"))
		return (ERR_MALLOC);
	return (0);
}

int	builtin_unset(char **argv, t_env **env)
{
	int	exitcode;
	int	i;

	exitcode = 0;
	i = 1;
	while (argv[i])
	{
		if (env_isname(argv[i]))
			env_unset(env, argv[i]);
		else
		{
			if (bt_error(argv[i]))
				return (-1);
			exitcode = 1;
		}
		i++;
	}
	return (exitcode);
}
