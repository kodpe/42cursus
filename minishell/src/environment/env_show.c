/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:48:53 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 22:55:16 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define ERR_WR_ENV "minimichel: env: write error"

void	dbg_show_expand(char *begin, char *value, char *end)
{
	if (!SHOW_EXPAND)
		return ;
	ft_dprintf(2, "expand: [");
	c_yellow();
	ft_dprintf(2, "%s", begin);
	c_red();
	ft_dprintf(2, "%s", value);
	c_blue();
	ft_dprintf(2, "%s", end);
	c_reset();
	ft_dprintf(2, "]\n");
}

int	env_show(int fd, t_env *env)
{
	while (env)
	{
		if (env_isname(env->name))
		{
			if (sc_write(fd, env->name, ERR_WR_ENV))
				return (1);
			if (sc_write(fd, "=", ERR_WR_ENV))
				return (1);
			if (sc_write(fd, env->value, ERR_WR_ENV))
				return (1);
			if (sc_write(fd, "\n", ERR_WR_ENV))
				return (1);
		}
		env = env->next;
	}
	return (0);
}

int	env_show_export(int fd, t_env *env)
{
	while (env)
	{
		if (env_isname(env->name))
		{
			if (sc_write(fd, "export ", ERR_WR_ENV))
				return (1);
			if (sc_write(fd, env->name, ERR_WR_ENV))
				return (1);
			if (sc_write(fd, "=", ERR_WR_ENV))
				return (1);
			if (sc_write(fd, "\"", ERR_WR_ENV))
				return (1);
			if (sc_write(fd, env->value, ERR_WR_ENV))
				return (1);
			if (sc_write(fd, "\"", ERR_WR_ENV))
				return (1);
			if (sc_write(fd, "\n", ERR_WR_ENV))
				return (1);
		}
		env = env->next;
	}
	return (0);
}
