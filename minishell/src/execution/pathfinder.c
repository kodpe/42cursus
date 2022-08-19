/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 00:57:24 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 21:16:25 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef __linux__
# define PATH_SEPARATOR "/"
#elif _WIN32
# define PATH_SEPARATOR "\\"
#else
# define PATH_SEPARATOR "/"
#endif

static bool	is_path(char *str, int *exitcode)
{
	int	i;

	*exitcode = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == *PATH_SEPARATOR)
		{
			*exitcode = test_access_ex(str, str, 0);
			return (true);
		}
		i++;
	}
	return (false);
}

static char	*test_current_directory(char *cmd, int *exitcode)
{
	char	*test;

	test = ft_strjointri(".", PATH_SEPARATOR, cmd);
	if (!test)
		return (NULL);
	*exitcode = test_access_ex(test, cmd, 0);
	return (test);
}

static char	*test_environment_path(char *cmd, char **path, int *exitcode)
{
	char	*test;
	int		i;

	test = NULL;
	i = 0;
	while (path[i])
	{
		free(test);
		test = ft_strjointri(path[i], PATH_SEPARATOR, cmd);
		if (!test)
			return (NULL);
		*exitcode = test_access_ex_no_msg(test);
		if (*exitcode == 0)
			break ;
		i++;
	}
	*exitcode = test_access_ex(test, cmd, 1);
	return (test);
}

char	*pathfinder(char *cmd, char **env_path, int *exitcode)
{
	if (!ft_strlen(cmd))
	{
		if (err_msg_2(cmd, ": command not found\n"))
		{
			*exitcode = 255;
			return (NULL);
		}
		*exitcode = EXIT_NOT_FOUND;
		return (ft_strdup(cmd));
	}
	if (is_path(cmd, exitcode))
		return (ft_strdup(cmd));
	if (env_path && env_path[0])
		return (test_environment_path(cmd, env_path, exitcode));
	return (test_current_directory(cmd, exitcode));
}
