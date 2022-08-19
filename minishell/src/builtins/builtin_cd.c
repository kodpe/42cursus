/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:17:42 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/30 10:07:13 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_pwd(t_env **env, char *serarien)
{
	char	*path;

	path = NULL;
	if (strcmp(serarien, "//"))
	{
		path = get_dir();
		if (!path)
			return (0);
		if (env_replace(env, "PWD", path))
			return (free(path), -1);
		if (env_replace(env, "?PWD", path))
			return (free(path), -1);
		return (free(path), 0);
	}
	if (env_replace(env, "PWD", "//"))
		return (-1);
	if (env_replace(env, "?PWD", "//"))
		return (-1);
	return (0);
}

int	set_env(t_env **env, char *pwd, char *serarien)
{
	if (env_replace(env, "OLDPWD", pwd))
	{
		free(pwd);
		return (-1);
	}
	free(pwd);
	return (set_pwd(env, serarien));
}

int	sc_chdir(char *path, t_env **env)
{
	char	*pwd;

	pwd = env_get(*env, "PWD");
	if (!pwd)
		return (-1);
	if (chdir(path))
	{
		free(pwd);
		if (errno == 13 || errno == 2)
		{
			if (err_msg_3_space_nl("minishell: cd: ", path, strerror(errno)))
				return (free(path), 0);
		}
		else
			perror("minishell: cd");
		return (1);
	}
	return (set_env(env, pwd, path));
}

int	cd_env(t_env **env, char *str)
{
	int		ret;
	char	*path;

	path = env_get(*env, str);
	if (!path)
		return (-1);
	if (ft_strlen(path) == 0)
	{
		free(path);
		if (err_msg_3("minishell: cd: ", str, " not set\n"))
			return (-1);
		return (1);
	}
	ret = sc_chdir(path, env);
	free(path);
	if (!strcmp(str, "OLDPWD") && ret == 0)
		return (builtin_pwd(*env));
	return (ret);
}

int	builtin_cd(char **argv, t_env **env)
{
	if (ft_ar_size(argv) > 2)
	{
		err_msg("minishell : cd: too many arguments\n");
		return (1);
	}
	if (ft_ar_size(argv) == 1 || !strcmp(argv[1], "--"))
		return (cd_env(env, "HOME"));
	if (!strcmp(argv[1], "-"))
		return (cd_env(env, "OLDPWD"));
	return (sc_chdir(argv[1], env));
}
