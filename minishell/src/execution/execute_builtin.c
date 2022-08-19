/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:58:12 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/29 19:16:03 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_one_builtin(t_cmd *cmd, char *name, t_env **env)
{
	if (!strcmp(name, "echo"))
		return (builtin_echo(cmd->argv));
	if (!strcmp(name, "cd"))
		return (builtin_cd(cmd->argv, env));
	if (!strcmp(name, "pwd"))
		return (builtin_pwd(*env));
	if (!strcmp(name, "export"))
		return (builtin_export(cmd->argv, env));
	if (!strcmp(name, "unset"))
		return (builtin_unset(cmd->argv, env));
	if (!strcmp(name, "env"))
		return (builtin_env(cmd->argv, *env));
	if (!strcmp(name, "exit"))
		return (builtin_exit(ft_arlen(cmd->argv), cmd->argv, *env, cmd));
	return (127);
}
