/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:26:11 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 21:27:50 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <sys/ioctl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
# include <dirent.h>
# include <signal.h>
# include <limits.h>

# include "../libft/libft.h"
# include "msh_token.h"
# include "msh_lexer.h"
# include "msh_parser.h"
# include "msh_environment.h"
# include "msh_execution.h"

# include "msh_wildcard.h"

# define NAME "mini_mishell"
# define MINISHELL_PROMPT "mini_mishell$ "

# define OLD_EXITCODE "?"

# define SUCCESS		0
# define ERR_MALLOC		1
# define ERR_FORK		-1

# define ERR_REDIR		-3

# define ERR_PIPE		-2
# define EXIT_ERR_PIPE 129

# define ERR_BAD_USE	2
# define EXIT_CANT_EXEC	126
# define EXIT_NOT_FOUND	127
// # define EXIT_FAIL_EXEC	128
/** SIGNAL EXITCODE    [129;159] **/

/** DEBUG OPTIONS **/
# define TEST_ISNAME 0
# define TEST_ENV_VAR 0
# define SHOW_ENV_INIT 0
# define SHOW_TOKEN 0
# define SHOW_BTREE 0
# define SHOW_BTREE_VERBOSE 0
# define SHOW_EXPAND 0
# define SHOW_WILDCARD 0
# define SHOW_DEBUG_WILDCARD 0
# define SHOW_COMMAND 0
# define SHOW_CMD_VERBOSE 0
# define SHOW_PIPE 0
# define SHOW_EXITCODE 0

extern int		g_g;

void	sig_exec(int signum);
void	sighandler(int signum);
void	sig_child(int signum);
void	sig_heredoc(int signum);
char	*get_line_input(int *ctrld);

/**
 * 		errors_msg.c
 */
void	err_msg(char *msg);
int		err_msg_2(char *name, char *msg);
int		err_msg_3(char *title, char *name, char *msg);
int		err_msg_3_space_nl(char *title, char *name, char *msg);

#endif /* MINISHELL_H */
