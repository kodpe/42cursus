/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:15:19 by sloquet           #+#    #+#             */
/*   Updated: 2022/05/25 13:53:32 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> /* access, pipe, dup, dup2, execve, fork */
# include <stdlib.h>
# include <fcntl.h> /* open */
# include <sys/wait.h> /* waitpid */
# include <stdio.h> /* perror */
# include "../libft/libft.h"

# define PIPEX_INFO 0
# define PRINT_PATHS 0
# define HEREDOC "here_doc"
# define TMP_FILE_HEREDOC ".tmp_pipex"
# define CLOSE -1

# define E_OUTFILE 1
# define E_ARG_NBR 2
# define E_HEREDOC 3
# define E_MALLOC 4
# define E_PIPE 5
# define E_SPLIT 6
# define E_FORK 7
# define E_EXECVE 8
# define E_NOT_FOUND 127

typedef struct s_pipex
{
	char	*in_name;
	char	*out_name;
	int		in;
	int		out;
	char	**paths;
	char	**cmds;
	int		heredoc;
	int		child;
	int		nbr_cmds;
	int		pipe_tips;
	int		*pipe;
	pid_t	*pid;
}			t_pipex;

t_pipex	*create_pipex(int ac, char **av, char **envp);
void	execute_cmd(t_pipex *p, int i, char **envp);

/**
 * 		destroy.c 5/5
 */
void	close_all_fd(t_pipex *p);
void	destroy_pipex(t_pipex *p, int exitcode);

/**
 * 		error.c
 */
void	error_msg(char *msg);
void	error_exit(int exitcode, char *msg);
void	error_cmd_msg(char *cmd, char **paths);

/**
 * 		debug.c
 */
void	pipex_info_create(t_pipex *p);
int		pipex_info_child(t_pipex *p, int i, int status);
int		waitpid_status(t_pipex *p);

#endif /* PIPEX_H */
