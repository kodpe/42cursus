/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:50:05 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 23:02:46 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	bt_error(char *str)
{
	if (err_msg_3("minishell: export: `", str, "': not a valid identifier\n"))
		return (ERR_MALLOC);
	return (0);
}

static int	valid_name(char *str)
{
	char	*test;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	test = ft_strldup(str, i + 1);
	if (!test)
		return (-1);
	if (env_isname(test))
	{
		if (!str[i])
			return (free(test), 2);
		else
			return (free(test), SUCCESS);
	}
	return (free(test), 1);
}

static int	do_export(char *arg, t_env **env)
{
	char	*name;
	char	*value;

	name = env_get_name(arg);
	if (!name)
		return (-1);
	value = env_get_value(arg);
	if (!value)
		return (free(name), -1);
	if (env_replace(env, name, value))
		return (free(name), free(value), -1);
	free(name);
	free(value);
	return (SUCCESS);
}

int	builtin_export(char **argv, t_env **env)
{
	int	exitcode;
	int	i;
	int	ret;

	if (ft_arlen(++argv) == 0)
		return (env_show_export(1, *env));
	exitcode = 0;
	i = 0;
	while (argv[i])
	{
		ret = valid_name(argv[i]);
		if (ret == -1)
			return (-1);
		if (ret == 0 && do_export(argv[i], env) == -1)
			return (-1);
		else if (ret == 1)
		{
			if (bt_error(argv[i]))
				return (-1);
			exitcode = 1;
		}
		i++;
	}
	return (exitcode);
}

/*

export g==		-->		export g="="
export g		-->		export g="="
export g=		-->		export g=""
export h		-->		export h
export h=""		-->		export h=""
export h=''		-->		export h=''
export "p"=q	-->		export p="q"
export g3		-->		export g3
export _4_		-->		export _4_
export _		-->		NA

export =a		-->		bash: export: « =a » : identifiant non valable
export 42		-->		bash: export: « 42 » : identifiant non valable
export ""		-->		bash: export: «    » : identifiant non valable
export ''		-->		bash: export: «    » : identifiant non valable
export "  "		-->		bash: export: «      » : identifiant non valable
export "'  '"	-->		bash: export: « '  ' » : identifiant non valable
export "a b"	-->		bash: export: « "a b" » : identifiant non valable

*/
