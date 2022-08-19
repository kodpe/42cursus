/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expandone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 02:18:56 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/22 16:56:48 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_trijoin(char *begin, char *value, char *end, int *i)
{
	char	*new;

	new = NULL;
	if (begin && value && end)
	{
		dbg_show_expand(begin, value, end);
		new = ft_strjointri(begin, value, end);
		*i = ft_strlen(begin) + ft_strlen(value);
	}
	free(begin);
	free(value);
	free(end);
	return (new);
}

static char	*expand_env_var(char *str, int *i, t_env *env)
{
	char	*name;
	char	*value;
	char	*begin;
	char	*end;

	name = env_get_name(&str[*i]);
	value = env_get(env, name);
	begin = ft_strldup(str, *i);
	end = ft_strdup(&str[*i + ft_strlen(name)]);
	free(name);
	free(str);
	return (expand_trijoin(begin, value, end, i));
}

static char	*expand_exitcode(char *str, int *i, t_env *env)
{
	char	*value;
	char	*begin;
	char	*end;

	begin = ft_strldup(str, *i);
	value = env_get(env, "?");
	end = ft_strdup(&str[*i + 1]);
	free(str);
	return (expand_trijoin(begin, value, end, i));
}

static char	*ex_two_dollars(char *str, int *i)
{
	char	*begin;
	char	*value;
	char	*end;

	begin = ft_strldup(str, *i);
	value = ft_strdup("");
	end = ft_strdup(&str[*i + 1]);
	free(str);
	return (expand_trijoin(begin, value, end, i));
}

char	*env_expandone(char *str, int *i, t_env *env)
{
	if (str[*i] == '$')
		return (ex_two_dollars(str, i));
	if (str[*i] == '?')
		return (expand_exitcode(str, i, env));
	return (expand_env_var(str, i, env));
}
