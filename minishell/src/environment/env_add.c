/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:50:22 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/27 00:31:54 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_new_var(char *var)
{
	t_env	*new;
	int		i;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	new->name = ft_strldup(var, i + 1);
	if (!new->name)
	{
		free(new);
		return (NULL);
	}
	new->value = ft_strdup(&var[i + 1]);
	if (!new->value)
	{
		free(new->name);
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

static int	env_add_back(t_env **lst, t_env *new)
{
	t_env	*root;

	if (!new)
		return (1);
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	root = *lst;
	while (*lst && (*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
	*lst = root;
	return (0);
}

int	env_add(t_env **env, char *var)
{
	if (env_add_back(env, env_new_var(var)))
	{
		env_destroy(env);
		return (ERR_MALLOC);
	}
	return (SUCCESS);
}
