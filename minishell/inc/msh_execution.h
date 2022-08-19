/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execution.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:58:16 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 20:32:36 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_EXECUTION_H
# define MSH_EXECUTION_H

# include "minishell.h"

# define NODE_AND '&'
# define NODE_OR '|'

# define O_CWT 01101
# define O_CWA 02101

// # define STR_CMD_INVALID	"CMD_INVALID"
// # define STR_CMD_VALIDEX	"CMD_VALIDEX"
// # define STR_CMD_BUILTIN	"CMD_BUILTIN"

typedef struct s_cmd
{
	t_token			*list_cmd;
	t_token			*list_redir;
	char			**argv;
	char			**envp;
	char			**path;
	char			*pathname;
	bool			isbuiltin;
	bool			isempty;
	int				pos;
	int				fd_in;
	int				fd_out;
	t_btree			**tree;
	pid_t			*pid;
	t_env			**env;
	int				save_stdin;
	int				save_stdout;
	struct s_cmd	**croot;
	struct s_cmd	*next;
}	t_cmd;

//CMD CREATION
int		pre_exec(t_btree *node, t_env **env, t_btree **root);
int		prep(t_cmd *cmd, t_env *env);
int		concat_split(t_cmd *cmd);
void	cmd_destructor(t_cmd **cmd);

t_cmd	*create_pipeline(t_token *pipeline, t_env **env);
void	save_i_o(t_cmd *cmd);
void	res_i_o(t_cmd *cmd);

int		fill_cmd(t_cmd **cmd, t_token *p);
t_cmd	*create_cmd(int i);
t_cmd	*split_command(t_token *pipeline);

//CONCATENATION
t_token	*concatene(t_token *t);

//DEBUG
void	t_cmd_print(t_cmd *cmd, t_token *Gazoduc, bool show_status);

/**
 * 		execution/
 */
int		execute_pipeline(t_token *pipeline, t_env **env, t_btree **root);
int		one_pipe(t_cmd *cmd, pid_t *pid);
void	child_process(t_cmd *cmd);
int		exec(t_cmd *cmd);
void	destroy_exit(t_cmd *cmd, int exitcode);

int		test_access_ex_no_msg(char *path);
int		test_access_ex(char *path, char *cmd, int envpath);
char	*pathfinder(char *cmd, char **env_path, int *exitcode);
int		execute_one_builtin(t_cmd *cmd, char *name, t_env **env);

/**
 * 		pipe.c
 */
void	close_fdtab(int **fdtab, size_t size);
void	show_fdtab(int **fdtab, size_t size);
void	destroy_intab(int **fdtab, size_t size);
int		**create_pipes(size_t size);

/**/
pid_t	*create_pidtab(size_t nb_fork);
void	wait_all_child(pid_t *pid, int i);

/**
 * 		exitcode.c
 */
int		pipeline_exitcode(pid_t *pid, size_t nb_fork);

/**
 * 		builtins/
 */
int		builtin_echo(char **argv);
int		builtin_env(char **argv, t_env *env);
int		builtin_export(char **argv, t_env **env);
int		builtin_unset(char **argv, t_env **env);
int		builtin_exit(int ac, char **argv, t_env *env, t_cmd *cmd);
int		builtin_pwd(t_env *env);
int		builtin_cd(char **argv, t_env **env);

/**
 * 		builtins_utils/
 */
char	*get_dir(void);
int		set_pwd(t_env **env, char *serarien);
void	res_i_o(t_cmd *cmd);

/**
 * 		redir/
 */
int		set_redir(t_token *redir, t_cmd *cmd);
int		open_redir_in(t_token *redir, t_cmd *cmd);
int		fill_here_doc(int fd, char *eof, t_env *env, int expanded);
char	*get_tmp_file(void);
int		here_doc_for_each_cmd(t_cmd *cmd);
void	unlink_for_all_cmd(t_cmd *cmd);
void	unlink_last_here_doc(t_token *redir);
int		unlink_sc(char *str);

#endif /* MSH_EXECUTION_H */
