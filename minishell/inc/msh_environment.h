/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_environment.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:18:08 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/28 15:58:41 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_ENVIRONMENT_H
# define MSH_ENVIRONMENT_H

# include "msh_token.h"

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

/**
 * 		environment/
 * */
t_env	*env_new_var(char *var);
int		env_add(t_env **env, char *var);
void	env_del(t_env **env, char *name);
t_env	*env_init(char **envp);
void	env_destroy(t_env **env);
size_t	env_size(t_env *env);

char	*expander(char *str, t_env *env);
t_token	*env_expander(t_token *pipeline, t_env *env);
int		env_expander_here_doc(t_token **t);
int		detect_last_dollar(t_token *t);
t_token	*env_split_token(t_token *t, t_tolkien name, char sep);

char	*env_expandone(char *str, int *i, t_env *env);
char	*env_get_name(char *str);
char	*env_get_value(char *str);
char	*env_get(t_env *env, char *name);
bool	env_exist(t_env *env, char *name);
bool	env_isname(char *name);
int		env_replace(t_env **env, char *name, char *value);

void	dbg_show_expand(char *begin, char *value, char *end);
int		env_show(int fd, t_env *env);
int		env_show_export(int fd, t_env *env);

int		env_update_exitcode(t_env *env, int exitcode);
int		env_old_exitcode(t_env *env);

#endif /* MSH_ENVIRONMENT_H */
