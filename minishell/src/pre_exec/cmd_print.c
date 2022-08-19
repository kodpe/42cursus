/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:18:14 by chsimon           #+#    #+#             */
/*   Updated: 2022/07/29 17:18:02 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cmd_show_status(t_cmd *cmd)
{
	ft_dprintf(2, "status   : ");
	c_bold();
	c_cyan();
	if (cmd->isbuiltin)
		ft_dprintf(2, "%s\n", "builtin");
	c_green();
	if (cmd->pathname)
		ft_dprintf(2, "%s\n", "executable");
	c_red();
	if (!cmd->pathname && !cmd->isbuiltin)
		ft_dprintf(2, "%s\n", "invalid");
	c_reset();
}

char	*xspace(size_t x)
{
	return ((char *)ft_memset((char *)ft_calloc(x + 1), ' ', x));
}

void	show_array(char *name, char	**a, bool opt, void (*c)(void))
{
	char	*s;
	size_t	i;
	size_t	x;

	c();
	i = 0;
	ft_dprintf(2, "**:%p\n", a);
	while (a && a[i])
	{
		x = 6 - ft_strlen(name);
		if (i < 10)
			x++;
		s = xspace(x);
		if (!opt || i == 0 || !a[i + 1])
			ft_dprintf(2, "%s[%d]%s: %s\n", name, i, s, a[i]);
		free(s);
		i++;
	}
	c_reset();
}

void	t_cmd_print(t_cmd *cmd, t_token *Gazoduc, bool show_status)
{
	if (!SHOW_COMMAND)
		return ;
	print_token_list_one_line(Gazoduc, "gazoduc  :", c_yellow);
	while (cmd)
	{
		ft_putnl_fd(2);
		if (show_status)
			cmd_show_status(cmd);
		if (cmd->argv && cmd->argv[0])
			ft_dprintf(2, "name/path : %s (%s)\n", cmd->argv[0], cmd->pathname);
		ft_dprintf(2, "pos       : %d\n", cmd->pos);
		if (SHOW_CMD_VERBOSE)
		{
			show_array("env", cmd->envp, false, c_green);
			show_array("path", cmd->path, false, c_red);
		}
		show_array("argv", cmd->argv, false, c_reset);
		print_token_list_one_line(cmd->list_redir, "redirections :", c_blue);
		print_token_list(cmd->list_redir, "Redirections");
		cmd = cmd->next;
	}
}
