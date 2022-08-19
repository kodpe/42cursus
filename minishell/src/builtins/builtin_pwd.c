/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:46:09 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/29 19:35:08 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_dir(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
	{
		perror("pwd: error retrieving current directory:\
getcwd: cannot access parent directories");
		return (NULL);
	}
	return (path);
}

int	builtin_pwd(t_env *env)
{
	char	*path;

	path = env_get(env, "?PWD");
	if (path == NULL)
		return (1);
	if (ft_strlen(path) == 0)
		path = get_dir();
	sc_write(1, path, "Failed write in builtin pwd\n");
	sc_write(1, "\n", "Failed write in builtin pwd\n");
	if (!path)
		return (1);
	free(path);
	return (0);
}
