/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:56:24 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 21:23:24 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	test_access_ex_no_msg(char *path)
{
	struct stat	buf;

	if (0 > stat(path, &buf))
	{
		if (errno == ENOENT)
			return (EXIT_NOT_FOUND);
		return (EXIT_CANT_EXEC);
	}
	if (S_ISDIR(buf.st_mode))
		return (EXIT_CANT_EXEC);
	if (!S_ISREG(buf.st_mode))
		return (EXIT_CANT_EXEC);
	if (0 > access(path, F_OK | X_OK))
		return (EXIT_CANT_EXEC);
	return (SUCCESS);
}

static int	test_stat_part2(struct stat buf, char *cmd)
{
	if (S_ISDIR(buf.st_mode))
	{
		if (err_msg_3("msh: ", cmd, ": Is a directory\n"))
			return (255);
		return (EXIT_CANT_EXEC);
	}
	if (!S_ISREG(buf.st_mode))
	{
		if (err_msg_3("msh: ", cmd, ": Not a regular file\n"))
			return (255);
		return (EXIT_CANT_EXEC);
	}
	return (SUCCESS);
}

static int	test_stat(char *path, char *cmd, int envpath)
{
	struct stat	buf;

	if (0 > stat(path, &buf))
	{
		if (envpath)
		{
			if (err_msg_2(cmd, ": command not found\n"))
				return (255);
			return (EXIT_NOT_FOUND);
		}
		if (err_msg_3("msh: ", cmd, ": No such file or directory\n"))
			return (255);
		return (EXIT_NOT_FOUND);
	}
	return (test_stat_part2(buf, cmd));
}

int	test_access_ex(char *path, char *cmd, int envpath)
{
	int	exitcode;

	exitcode = test_stat(path, cmd, envpath);
	if (exitcode)
		return (exitcode);
	if (0 > access(path, F_OK | X_OK))
	{
		if (err_msg_3("msh: ", cmd, ": Permission denied\n"))
			return (255);
		return (EXIT_CANT_EXEC);
	}
	return (SUCCESS);
}
