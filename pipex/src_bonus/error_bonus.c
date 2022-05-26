/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:00:55 by sloquet           #+#    #+#             */
/*   Updated: 2022/05/25 16:00:55 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error_msg(char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	else
		perror("Error");
}

void	error_exit(int exitcode, char *msg)
{
	error_msg(msg);
	exit(exitcode);
}

void	error_cmd_msg(char *cmd, char **paths)
{
	write(2, cmd, ft_strlen(cmd));
	if (paths)
	{
		if (ft_strchr(cmd, '/'))
			write(2, ": No such file or directory\n", 28);
		else
			write(2, ": command not found\n", 20);
	}
	else
		write(2, ": No such file or directory\n", 28);
}
