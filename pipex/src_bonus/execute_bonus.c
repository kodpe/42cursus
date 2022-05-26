/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:01:05 by sloquet           #+#    #+#             */
/*   Updated: 2022/05/25 16:01:08 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

#ifdef __linux__
# define PATH_SEPARATOR "/"
#elif _WIN32
# define PATH_SEPARATOR "\\"
#else
# define PATH_SEPARATOR "/"
#endif

#define VALID_PATH 1
#define ISNOT_PATH 0
#define WRONG_PATH -1

/**
 * \return 1 valid path, 0 isnot path, -1 wrong path
 */
static int	ft_ispath(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == *PATH_SEPARATOR)
		{
			if (0 > access(str, F_OK) || 0 > access(str, X_OK))
				return (WRONG_PATH);
			return (VALID_PATH);
		}
		i++;
	}
	return (ISNOT_PATH);
}

static char	*test_current_directory(char *cmd)
{
	char	*test;

	test = ft_strjointri(".", PATH_SEPARATOR, cmd);
	if (!test || 0 > access(test, X_OK))
	{
		free(test);
		return (NULL);
	}
	return (test);
}

static char	*test_environment_paths(char *cmd, char **paths)
{
	char	*test;
	int		i;

	i = 0;
	while (paths[i++])
	{
		test = ft_strjointri(paths[i], PATH_SEPARATOR, cmd);
		if (!test || 0 == access(test, X_OK))
			break ;
		free(test);
		test = NULL;
	}
	return (test);
}

static char	*pathfinder(char *cmd, char **paths)
{
	int		i;

	i = ft_ispath(cmd);
	if (i == WRONG_PATH)
		return (NULL);
	if (i == VALID_PATH)
		return (ft_strdup(cmd));
	if (i == ISNOT_PATH && !paths)
		return (test_current_directory(cmd));
	return (test_environment_paths(cmd, paths));
}

/**
 * fprintf(stderr, "==> execve: %s : %s : envp\n", cmd_path, p->cmds[i]);
**/
void	execute_cmd(t_pipex *p, int i, char **envp)
{
	char	*cmd_path;
	char	**cmd_splited;

	cmd_splited = ft_split(p->cmds[i], ' ');
	if (!cmd_splited)
	{
		error_msg("cmd split failed");
		destroy_pipex(p, E_SPLIT);
	}
	cmd_path = pathfinder(cmd_splited[0], p->paths);
	if (!cmd_path)
	{
		error_cmd_msg(cmd_splited[0], p->paths);
		ft_arfree(cmd_splited);
		destroy_pipex(p, E_NOT_FOUND);
	}
	if (execve(cmd_path, cmd_splited, envp))
	{
		perror(cmd_path);
		free(cmd_path);
		ft_arfree(cmd_splited);
		destroy_pipex(p, E_EXECVE);
	}
}
