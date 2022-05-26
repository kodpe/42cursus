/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:53:01 by sloquet           #+#    #+#             */
/*   Updated: 2022/05/25 15:58:23 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * envp : PATH=/usr/local/sbin:/usr/local/bin:/usr/...
 *             ^              :              :
 *        012345            split          split
 */
static char	**split_env_path(char **envp)
{
	char	**paths;

	paths = NULL;
	while (*envp && ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (*envp && ft_strlen(*envp) > 5)
	{
		if (ft_strchr(*envp, ':'))
		{
			paths = ft_split(*envp + 5, ':');
			if (!paths)
				return (NULL);
		}
		else
		{
			paths = (char **)malloc(sizeof(char *) * 2);
			if (!paths)
				return (NULL);
			paths[0] = ft_strdup(*envp + 5);
			paths[1] = NULL;
		}
	}
	return (paths);
}

static void	open_files(t_pipex *p, int ac, char **av)
{
	if (p->heredoc)
		p->in_name = ft_strdup(TMP_FILE_HEREDOC);
	else
		p->in_name = ft_strdup(av[1]);
	p->out_name = ft_strdup(av[ac - 1]);
	if (!p->in_name || !p->out_name)
		destroy_pipex(p, E_MALLOC);
	p->in = open(p->in_name, O_RDONLY);
	if (0 > p->in)
		perror(p->in_name);
	if (p->heredoc)
		p->out = open(p->out_name, O_WRONLY | O_CREAT | O_APPEND, 00644);
	else
		p->out = open(p->out_name, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (0 > p->out)
	{
		perror(p->out_name);
		destroy_pipex(p, E_OUTFILE);
	}
}

/**
	fprintf(stderr, "pipe[%d][%d]\n", 2 * i, 2 * i + 1);
	fprintf(stderr, "[%d] %d\n", 2 * i, p->pipe[2 * i]);
	fprintf(stderr, "[%d] %d\n", 2 * i + 1, p->pipe[2 * i + 1]);
*/
static void	initialize_pipex(t_pipex *p)
{
	int	i;

	p->in = -2;
	p->out = -2;
	p->in_name = NULL;
	p->out_name = NULL;
	p->pipe = NULL;
	p->pid = NULL;
	p->pipe_tips = 2 * (p->nbr_cmds - 1);
	p->pipe = ft_newtab(p->pipe_tips);
	if (!p->pipe)
		destroy_pipex(p, E_MALLOC);
	i = 0;
	while (i < p->nbr_cmds - 1)
	{
		if (0 > pipe(p->pipe + 2 * i))
		{
			perror("pipe");
			destroy_pipex(p, E_PIPE);
		}
		i++;
	}
	p->pid = malloc(sizeof(pid_t) * p->nbr_cmds);
	if (!p->pid)
		destroy_pipex(p, E_MALLOC);
}

/**
 * ./p infile cmd1 cmd2 outfile
 *        1    2    3     4                ac = 5; nbr_cmds = ac - 3; start = 2;
 * 
 * ./p here_doc LIMITER cmd1 cmd2 outfile
 * 		  1        2     3    4     5      ac = 6; nbr_cmds = ac - 4; start = 3;
 */
t_pipex	*create_pipex(int ac, char **av, char **envp)
{
	t_pipex	*p;

	if (ac != 5)
		error_exit(E_ARG_NBR, "Error: invalid arguments number\n");
	p = malloc(sizeof(t_pipex));
	if (!p)
		exit(E_MALLOC);
	p->cmds = av + 2;
	p->heredoc = 0;
	p->nbr_cmds = ac - 3 - p->heredoc;
	p->paths = split_env_path(envp);
	p->child = -1;
	initialize_pipex(p);
	open_files(p, ac, av);
	return (p);
}
