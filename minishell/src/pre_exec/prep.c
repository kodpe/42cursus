/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:02:44 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/29 21:04:50 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**convert_token(t_token *t)
{
	char	**converted;
	size_t	i;

	i = 0;
	converted = ft_calloc(sizeof(char **) * (token_size(t) + 1));
	if (!converted)
		return (NULL);
	while (t)
	{
		if (t->name != T_WHITESPACE)
		{
			if (t->name == T_WORD && (ft_strlen(t->content) || t->is_concated))
			{
				converted[i] = strdup(t->content);
				if (!converted[i])
				{
					ft_arfree(converted);
					return (NULL);
				}
				i++;
			}
		}
		t = t->next;
	}
	return (converted);
}

static char	**convert_env(t_env *env)
{
	char	**converted;
	size_t	i;

	i = 0;
	converted = ft_calloc(sizeof(char **) * (env_size(env) + 1));
	if (!converted)
		return (NULL);
	while (env)
	{
		converted[i] = ft_strjointri(env->name, "=", env->value);
		if (!converted[i])
		{
			ft_arfree(converted);
			return (NULL);
		}
		i++;
		env = env->next;
	}
	return (converted);
}

static char	**env_split_path(t_env *env)
{
	char	*path;
	char	**splitted;

	path = env_get(env, "PATH");
	splitted = ft_split(path, ':');
	free(path);
	return (splitted);
}

static bool	is_builtin(char *name)
{
	if (!name)
		return (false);
	if (!strcmp(name, "echo"))
		return (true);
	if (!strcmp(name, "cd"))
		return (true);
	if (!strcmp(name, "pwd"))
		return (true);
	if (!strcmp(name, "export"))
		return (true);
	if (!strcmp(name, "unset"))
		return (true);
	if (!strcmp(name, "env"))
		return (true);
	if (!strcmp(name, "exit"))
		return (true);
	return (false);
}

int	prep(t_cmd *cmd, t_env *env)
{
	int	n;

	n = 0;
	while (cmd)
	{
		if (cmd->list_cmd)
		{
			cmd->argv = convert_token(cmd->list_cmd);
			if (!cmd->argv)
				return (ERR_MALLOC);
		}
		cmd->envp = convert_env(env);
		if (!cmd->envp)
			return (ERR_MALLOC);
		cmd->path = env_split_path(env);
		if (!cmd->path)
			return (ERR_MALLOC);
		if (cmd->argv)
			cmd->isbuiltin = is_builtin(cmd->argv[0]);
		cmd->pos = n;
		n++;
		cmd = cmd->next;
	}
	return (0);
}
