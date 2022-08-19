/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:47:25 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 18:58:36 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	__test_init_var(t_env **env)
{
	if (!TEST_ENV_VAR)
		return (SUCCESS);
	if (env_add(env, "T1=   a b  c  "))
		return (ERR_MALLOC);
	if (env_add(env, "T2=d e f"))
		return (ERR_MALLOC);
	if (env_add(env, "w1=*t*"))
		return (ERR_MALLOC);
	if (env_add(env, "w2=*"))
		return (ERR_MALLOC);
	if (env_add(env, "w3=.*"))
		return (ERR_MALLOC);
	if (env_add(env, "w4=.*t"))
		return (ERR_MALLOC);
	if (env_add(env, "e4=$a$b$c$$d$$$"))
		return (ERR_MALLOC);
	if (env_add(env, "ew=hello les amis *"))
		return (ERR_MALLOC);
	if (env_add(env, "E2="))
		return (ERR_MALLOC);
	if (env_add(env, "A=ls"))
		return (ERR_MALLOC);
	if (env_add(env, "B= -la"))
		return (ERR_MALLOC);
	return (SUCCESS);
}

static void	_isname(char *name)
{
	if (env_isname(name))
	{
		c_green();
		ft_dprintf(2, "env_isname() OK [%s]\n", name);
		c_reset();
	}
	else
	{
		c_red();
		ft_dprintf(2, "env_isname() KO [%s]\n", name);
		c_reset();
	}
}

static void	__test_env_isname(void)
{
	if (!TEST_ISNAME)
		return ;
	_isname("");
	_isname(" ");
	_isname("=");
	_isname("_");
	_isname("-");
	_isname(".");
	_isname("0");
	_isname("z");
	_isname("abc0");
	_isname("0abc");
	_isname("abc0_");
	_isname("0abc=");
	_isname("a1b2c3");
	_isname("a b c");
	_isname("a123");
	_isname(" a123");
}

static int	init_var(t_env **env)
{
	if (env_add(env, "?=0"))
		return (ERR_MALLOC);
	if (env_add(env, "?PWD="))
		return (ERR_MALLOC);
	return (SUCCESS);
}

t_env	*env_init(char **envp)
{
	t_env	*env;
	int		i;

	env = NULL;
	if (init_var(&env))
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (env_add(&env, envp[i]))
			return (NULL);
		i++;
	}
	if (set_pwd(&env, ""))
		return (NULL);
	if (__test_init_var(&env))
		return (NULL);
	if (SHOW_ENV_INIT)
		env_show(2, env);
	__test_env_isname();
	return (env);
}
