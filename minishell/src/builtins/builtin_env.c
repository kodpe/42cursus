/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:08:58 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/30 10:08:01 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define ERR_ARG_ENV "mini_mishell: env: invalid argument "
#define ERR_OPT_ENV "mini_mishell: env: unrecognized option "
#define WARNING_ENV "\nmini_mishell: env doesn't accept \
any arguments or options\n"

static int	bt_error(char *str)
{
	if (str[0] == '-')
	{
		if (err_msg_3(ERR_OPT_ENV, str, WARNING_ENV))
			return (-1);
	}
	else
	{
		if (err_msg_3(ERR_ARG_ENV, str, WARNING_ENV))
			return (-1);
	}
	return (0);
}

int	builtin_env(char **argv, t_env *env)
{
	if (ft_arlen(argv) == 1)
		return (env_show(1, env));
	if (bt_error(argv[1]))
		return (-1);
	return (2);
}
